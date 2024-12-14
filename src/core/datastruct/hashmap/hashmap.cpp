#include "./hashmap.h"

using namespace app;

HashMap::HashMap()
{
    counter = 0;
    lastId = 0;
}

bool HashMap::easyGetElement(int id, ListData *element)
{
    if (id == 0)
    {
        element = start;
        return true;
    }

    if (id == counter)
    {
        element = end;
        return true;
    }

    if (id == start->next->element->id)
    {
        element = start->next;
        return true;
    }

    if (id == end->back->element->id)
    {
        element = end->back;
        return true;
    }

    if (id == mid->element->id)
    {
        element = mid;
        return true;
    }

    if (id == mid->next->element->id)
    {
        element = mid->next;
        return true;
    }

    if (id == mid->back->element->id)
    {
        element = mid->back;
        return true;
    }

    return false;
}

void HashMap::getElement(int id, ListData *element)
{

    bool easy = easyGetElement(id, element);

    if (easy)
        return;

    ListElement aux;
    aux = new ListData;

    for (int i = 1; i <= counter; i++)
    {
        if (id > mid->element->id)
        {
        }
    }
}

int HashMap::getMidId()
{
    return ((counter + 1) / 2) - 1;
}

void HashMap::updateMid()
{
    if (counter == 0)
        return;

    if (counter == 1)
    {
        mid = start;
        return;
    }

    int idMid = getMidId();

    if (mid->element->id == idMid)
        return;

    ListElement aux;
    aux = new ListData;

    aux->element = mid->element;
    aux->next = mid->next;
    aux->back = mid->back;

    for (int i = 2; i <= counter; i++)
    {

        if (aux->element->id > idMid)
        {
            aux = aux->back;
            continue;
        }

        if (aux->element->id < idMid)
        {
            aux = aux->next;
            continue;
        }

        if (aux->element->id == idMid)
        {
            mid = aux;
            break;
        }
    }

    delete aux;
}

void HashMap::add(const char &data, HashData *hash)
{
    ListElement element;
    element = new ListData;

    element->element->data = data;
    element->element->id = lastId;
    element->next = nullptr;
    element->back = nullptr;

    hash = element->element;

    if (counter == 0)
    {
        start = element;

        end = element;
        end->back = start;

        mid = element;
        mid->back = start;
    }
    else
    {
        element->back = end;
        end->next = element;
        end = element;
        updateMid();
    }

    counter += 1;
    lastId += 1;
}

void HashMap::get(int id, HashData *hash)
{
}