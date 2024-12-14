#include <iostream>

namespace app
{

    class HashMap
    {
    private:
        struct HashData
        {
            int id;
            char &data;
        };
        typedef HashData *HashElement;

        struct ListData
        {
            HashElement element;
            ListData *next;
            ListData *back;
        };
        typedef ListData *ListElement;

        ListElement start;
        ListElement end;
        ListElement mid;

        int counter;
        int lastId;

        void getElement(int id, ListData *element);
        bool easyGetElement(int id, ListData *element);
        void updateMid();
        int getMidId();

    public:
        HashMap();
        void add(const char &data, HashData *hash);
        void get(int id, HashData *hash);
        void remove(int id, HashData *hash);
    };

}