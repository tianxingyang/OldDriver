#include <cstdio>
#include "_skiplist.h"
#include <cassert>

/*
学生得分高的排前面，得分一样的，年龄小的排前面，注意skiplist是升序排列的
*/
struct StudentSort
{
    int uin;
    int score;
    int age;

    bool operator==(const StudentSort& a) const
    {
        return this->score == a.score && this->age == a.age;
    }

    bool operator < (const StudentSort& a) const
    {
        if (this->score > a.score)
        {
            return true;
        }
        else if (this->score == a.score && this->age < a.age)
        {
            // 得分相同，年龄小的牛逼一些
            return true;
        }

        return false;
    }
    void ShowMe()
    {
        printf("uin=%d\tscore=%d\tage=%d\n", this->uin, this->score, this->age);
    }
};

struct ScoreCompare
{
    int operator() (const StudentSort*& pstLeft, const StudentSort*& pstRight) const
    {
        if (*pstLeft < *pstRight)
        {
            return 1;
        }
        else if (*pstLeft == *pstRight)
        {
            return 0;
        }

        return -1;
    }
};


int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("%s NodeNum \n", argv[0]);
        return 0;
    }

    int num = 1000;
    assert(num>0);
    srand(time(NULL));

    SkipList< StudentSort*, int, ScoreCompare> skiplist(12);
    StudentSort* students = new StudentSort[num];

    // construct skip list
    for (int i = 0; i < num; i++)
    {
        students[i].uin = i + 1;
        students[i].score = rand() % 150;
        students[i].age = 15 + rand() % 100;
        StudentSort sortKey;
        sortKey.age = students[i].age;
        sortKey.score = students[i].score;
        int rank = skiplist.Insert(&students[i], i + 1);
    }

    skiplist.PrintMe();

    return 0;
}

