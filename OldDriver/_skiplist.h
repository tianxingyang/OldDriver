/*
	��Ҫ�ο�redis��skiplistʵ�� (t_zset.c)����ʵ�ָ����ģ�滯
	�������򼯺Ϻ������ݽṹ(�����������а�)
    ʹ�ô�SkipListʱ����Ҫ�ṩ�º���COMPARE�����ڱȽ�score��key�Ĵ�С
	tangxing 2016/1/30

    ����: 2017/2/6 by tangxing
*/


#include <time.h>
#include <stdlib.h>
#include <vector>
using namespace std;

template <typename SCORE, typename KEY, typename COMPARE>
class SkipList
{
public:
    //��skiplist�в���Ԫ�ز����ز�����rank���������key�Ѵ��ڣ�����-1
    int Insert(const SCORE& score, const KEY& key);

    //����skiplist�е�Ԫ�ز����ظ��º��rank�������µ�key�����ڣ�����-1
    int Update(const SCORE& oldScore, const SCORE& newScore, const KEY& key);

    //ɾ��skiplist�е�Ԫ�أ���ɾ����key�����ڣ�����false
    bool Delete(const SCORE& score, const KEY& key);

    //�õ�skiplist��key����������key�����ڣ�����-1
    int GetRank(const SCORE& score, const KEY& key);

    //��ȡskiplist�е����һ��Ԫ�أ���ֵ������score��key��
    bool GetTail(SCORE& score, KEY& key);

    //����skiplist�����һ��Ԫ��
    void PopTail();

    //��ȡskiplist��ǰN��KEY
    int GetObjTopN( int n, vector<KEY>& v);

    //��ȡskiplist��ǰN��SCORE
    int GetScoreTopN( int n, vector<SCORE>& v);

    //��ȡskiplist�ĳ���
    int Length() { return m_length; }

    void PrintMe();

    SkipList(int level = SKIPLIST_DEFAULT_LEVEL)
    {
        this->_Creat(level);
    }

    ~SkipList()
    {
        this->_Free();
    }

private:
    struct SkipListNode
    {
        SCORE score;
        KEY key;
        SkipListNode* backward;
        struct SkipListLevel
        {
            SkipListNode* forward;
            int span;
            SkipListLevel() : forward(NULL), span(0)
            { }
        };
        SkipListLevel* level;

        SkipListNode() : backward(NULL), level(NULL)
        { }

        ~SkipListNode()
        {
            if (level)
            {
                delete[] level;
                level = NULL;
            }
        }
    };

    // 14����ԽϺõ�֧��2^14 ��Ԫ�����ڵ�skiplist
    const static int SKIPLIST_DEFAULT_LEVEL = 14;

    //skiplist���Ϊ32�㣬�������߻ή��Ч��
    const static int SKIPLIST_MAX_LEVEL = 32;

    // skiplist P = 1/4
	const static float SKIPLIST_P = 0.25;

private:
    //����һ������Ϊlevel��SkipList�ڵ�
    SkipListNode* _CreatNode(const SCORE& score, const KEY& key, int level)
    {
        SkipListNode* node = new SkipListNode();
        if (node==NULL)
        {
            return NULL;
        }

        node->score = score;
        node->key = key;
        node->level = new typename SkipListNode::SkipListLevel[level];

        return node;
    }

    void _FreeNode(SkipListNode* node)
    {
        delete node;
    }

    void _Creat( int MaxLevel);
    void _Free();
    int _RandomLevel();
    void DeleteNode(SkipListNode* x, SkipListNode** update);

private:
    struct SkipListNode *m_header, *m_tail;
    int m_maxLevel;
    int m_level;
    int m_length;
    COMPARE m_comparefunc;
};

template <typename SCORE, typename KEY, typename COMPARE>
void SkipList<SCORE, KEY, COMPARE>::_Creat( int MaxLevel)
{
    if (MaxLevel > SKIPLIST_MAX_LEVEL)
    {
	    MaxLevel = SKIPLIST_MAX_LEVEL;
    }

    m_maxLevel = MaxLevel;
    m_level = 1;
    m_length = 0;

    //��ʼ����ͷ
    SCORE tmpScore;
    KEY tmpKey;
    m_header = _CreatNode(tmpScore, tmpKey, MaxLevel);

    //���ñ�β
    m_tail = NULL;

    //�����������
    srandom( time(NULL) );
}


template <typename SCORE, typename KEY, typename COMPARE>
void SkipList<SCORE, KEY, COMPARE>::_Free()
{
    SkipListNode* x, *next;
    x = m_header;
    while(x)
    {
        next = x->level[0].forward;
        _FreeNode(x);
        x = next;
    }
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>:: _RandomLevel()
{
    int level = 1;
    while ((random()&0xFFFF) < (SKIPLIST_P * 0xFFFF))
        level += 1;

    return (level < m_maxLevel) ? level : m_maxLevel;
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>::Insert(const SCORE& score, const KEY& key)
{
    SkipListNode* x = m_header;
    //������¼���������У�ÿһ���Ͻ�Ҫ���½ڵ����ӵĽڵ�
    SkipListNode* update[m_maxLevel];
    int rank[m_maxLevel];

    for (int i = m_level -1; i >= 0; i--)
    {
        rank[i] = (i == (m_level -1)) ? 0 : rank[i + 1];
        while (x->level[i].forward &&
                (1 == m_comparefunc(score, x->level[i].forward->score)
                  ||(0 == m_comparefunc(score, x->level[i].forward->score) && 1 == m_comparefunc(key, x->level[i].forward->key))))
        {
            // ��� i ����m_level -1 ��, ��ô i �����ʼ rank ֵΪ i+1 ��� rank ֵ
            // ������� rank ֵһ����ۻ�, ���� rank[0] ��ֵ��һ�����½ڵ��ǰ�ýڵ����λ
            // rank[0] ���ں����Ϊ���� span ֵ�� rank ֵ�Ļ���
            rank[i] += x->level[i].span;
            x = x->level[i].forward;
        }
        // ��¼��Ҫ���½ڵ������ӵĽڵ�
        update[i] = x;
    }

    // ��ȡһ�����ֵ��Ϊ�½ڵ�Ĳ���
    int level = _RandomLevel();

    // ����½ڵ�Ĳ����ȱ��������ڵ�Ĳ�����Ҫ��,��ô��ʼ����ͷ�ڵ���δʹ�õĲ㣬
    //�������Ǽ�¼�� update ������, ����Ҳָ���½ڵ�
    if (level > m_level)
    {
        // ��ʼ��δʹ�ò�
        for (int i = m_level; i < level; i++)
        {
            rank[i] = 0;
            update[i] = m_header;
            update[i]->level[i].span = m_length;
        }
        // ���±��нڵ�������
        m_level = level;
    }

    // �����½ڵ�
    x = _CreatNode(score, key, level);

    // ��ǰ���¼��ָ��ָ���½ڵ㣬������Ӧ������
    for (int i = 0; i < level; i++)
    {
        // �����½ڵ�� forward ָ��
        x->level[i].forward = update[i]->level[i].forward;

        // ����;��¼�ĸ����ڵ�� forward ָ��ָ���½ڵ�
        update[i]->level[i].forward = x;

        //�����½ڵ��Խ�Ľڵ�����
        x->level[i].span = update[i]->level[i].span -(rank[0] - rank[i]);

        // �����½ڵ����֮����;�ڵ�� span ֵ
        update[i]->level[i].span = rank[0] - rank[i] + 1;
    }

    // δ�Ӵ��Ľڵ�� span ֵҲ��Ҫ��һ����Щ�ڵ�ֱ�Ӵӱ�ͷԽ���½ڵ�ָ���½ڵ����Ľڵ�
    for (int i = level; i < m_level; i++)
    {
        update[i]->level[i].span++;
    }

    //�����½ڵ��ǰһ���ڵ�
    x->backward = update[0] == m_header ? NULL : update[0];

    if (x->level[0].forward)
    {
        x->level[0].forward->backward = x;
    }
    else
    {
        m_tail = x;
    }

    m_length++;

    return rank[0] + 1;
}



template <typename SCORE, typename KEY, typename COMPARE>
void SkipList<SCORE, KEY, COMPARE>::DeleteNode(SkipListNode* x, SkipListNode** update)
{
    // �������кͱ�ɾ���ڵ� x �йصĽڵ�
    for (int i = 0; i < m_level; i++)
    {
        if (update[i]->level[i].forward == x)
        {
            update[i]->level[i].forward = x->level[i].forward;
            update[i]->level[i].span += x->level[i].span -1;
        }
        else
        {
            update[i]->level[i].span--;
        }
    }

    //���±�ɾ���ڵ�x�ĺ�һ���ڵ�ĺ���ָ��
    if (x->level[0].forward)
    {
        x->level[0].forward->backward = x->backward;
    }
    else
    {
        m_tail = x->backward;
    }

    //����ɾ���ڵ�����Ծ����Ψһ����߽ڵ㣬������Ծ��ǰ����
    while((m_level > 1) && (m_header->level[m_level-1].forward == NULL))
    {
        m_level--;
    }

    m_length--;
}


template <typename SCORE, typename KEY, typename COMPARE>
bool SkipList<SCORE, KEY, COMPARE>::Delete(const SCORE& score, const KEY& key)
{
    SkipListNode* x = m_header;
    SkipListNode* update[m_level];

    for (int i = m_level -1; i >= 0; i--)
    {
        while (x->level[i].forward &&
                (1 == m_comparefunc(score, x->level[i].forward->score)
                    ||(0 == m_comparefunc(score, x->level[i].forward->score) && 1 == m_comparefunc(key, x->level[i].forward->key))))
        {
            x = x->level[i].forward;
        }
        // ��¼��Ҫ���½ڵ������ӵĽڵ�
        update[i] = x;
    }

    x = x->level[0].forward;
    if (x && 0 == m_comparefunc(x->score, score) && 0 == m_comparefunc(x->key, key))
    {
        this->DeleteNode(x, update);
        this->_FreeNode(x);
        return true;
    }
    else
    {
        return false;
    }
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>::Update(const SCORE& oldScore, const SCORE& newScore,const KEY& key)
{
    if (!this->Delete(oldScore, key))
    {
        return -1;
    }

    return this->Insert(newScore, key);
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>::GetRank(const SCORE& score, const KEY& key)
{
    SkipListNode* x = m_header;
    int rank = 0;

    for (int i = m_level -1; i >= 0; i--)
    {
        while (x->level[i].forward &&
            (1 == m_comparefunc(score, x->level[i].forward->score)
                    ||(0 == m_comparefunc(score, x->level[i].forward->score) && 1 == m_comparefunc(key, x->level[i].forward->key))))
        {
            rank += x->level[i].span;
            x = x->level[i].forward;
        }
    }

    x = x->level[0].forward;

    if (x && 0 == m_comparefunc(score, x->score) && 0 == m_comparefunc(key, x->key))
    {
        return rank + 1;
    }

    return -1;
}


template <typename SCORE, typename KEY, typename COMPARE>
bool SkipList<SCORE, KEY, COMPARE>::GetTail(SCORE& score, KEY& key)
{
    if (m_tail)
    {
        score = m_tail->score;
        key = m_tail->key;
        return true;
    }
    else
    {
        return false;
    }
}


template <typename SCORE, typename KEY, typename COMPARE>
void SkipList<SCORE, KEY, COMPARE>::PopTail()
{
	if( m_tail == NULL )
	{
		return;
	}

	this->Delete(m_tail->score, m_tail->key);
}


template <typename SCORE, typename KEY, typename COMPARE>
void SkipList<SCORE, KEY, COMPARE>::PrintMe()
{
	printf("lenth: %u\n", m_length);
	printf("level: %d, max level: %d\n", m_level, m_maxLevel);
	printf("Head:");
	for( int j = 0; j < m_level; j++ )
	{
        if (m_header->level != NULL)
        {
		    printf("level[%d], span:%d\n", j, m_header->level[j].span);
        }
	}
	printf("---------------------\n");

	int i = 1;
	SkipListNode *x = m_header->level[0].forward;
	while( x != NULL )
	{
		printf("node %d: \n", i);
		printf("level: %d \n", x->levelLength );
		for(int j=0; j < (int)x->levelLength; j++ )
		{
            if (x->level != NULL)
            {
                printf("\tlevel[%d], span: %d\n", j ,x->level[j].span);
            }
		}
        x->score.showme();
		printf("---------------------\n");
		x = x->level[0].forward;
		i++;
	}
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>::GetObjTopN( int n, vector<KEY>& v)
{
	int i = 0;
	SkipListNode *x = m_header->level[0].forward;

	while(x && i < n)
	{
		v.push_back(x->key);
		x = x->level[0].forward;
		i++;
	}
    return i;
}

template <typename SCORE, typename KEY, typename COMPARE>
int SkipList<SCORE, KEY, COMPARE>::GetScoreTopN( int n, vector<SCORE>& v)
{
    int i = 0;
	SkipListNode *x = m_header->level[0].forward;

	while(x && i < n)
	{
		v.push_back(x->score);
		x = x->level[0].forward;
		i++;
	}

    return i;
}