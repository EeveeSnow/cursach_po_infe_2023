#include "string.h"
template <typename T> class List
{
public:
    List()
    {
        hundler = new T[now_size];
    }
    ~List()
    {
        delete[] hundler;
        delete[] temp;
    }

    List<T>& operator=(const List<T> &data)
    {
        if(&data != this)
        {
            hundler = data.hundler;
            now_size = data.now_size;
        }
        return *this;
    }

    void append(T info)
    {
        temp = new T[++now_size];
        for (unsigned int i = 0; i < now_size-1; i++)
        {
            temp[i] = hundler[i];
        }
        if (now_size != 0) temp[now_size - 1] = info;
        delete[] hundler;
        hundler = temp;
    }

    void pop(unsigned int n)
    {
        if (n < now_size)
        {
        temp = new T[now_size];
        for (unsigned int i = 0; i < n; i++)
        {
            temp[i] = hundler[i];
        }
        for (unsigned int i = ++n; i < now_size; i++)
        {
            temp[i-1] = hundler[i];
            temp[i-1].id = i;
        }
        now_size--;
        delete[] hundler;
        hundler = temp;
        }
    }

    List<T> search(char* info)
    {
        List<T> out;
        for (unsigned int i = 0; i < now_size; i++)
        {
            if(strstr(hundler[i].name,info) != NULL) out.append(hundler[i]);
        }
        return out;
    }

    void extend(unsigned int size)
    {
        if (now_size < size)
        {
            temp = new T[size];
            for (unsigned int i = 0; i < now_size; i++)
            {
                temp[i] = hundler[i];
            }
            delete[] hundler;
            hundler = temp;
            now_size = size;
        }
    }

    void clear()
    {
        now_size = 0;
        hundler = new T[now_size];
    }

    int size()
    {
        return now_size;
    }

    T* hundler;
    unsigned int now_size = 0;

private:
    T* temp = 0;
};