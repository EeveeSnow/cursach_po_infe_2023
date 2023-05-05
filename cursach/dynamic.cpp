template <typename T> class List
{
public:
    List()
    {
        now_size = 0;
        hundler = new T[now_size];
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
    unsigned int now_size;

private:
    T* temp;
};