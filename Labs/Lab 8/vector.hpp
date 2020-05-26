#include <stdlib.h>
template <class T>
class vector {
    private:
        T *v;
        int s;
        int c;
    public:
        vector(){
            s=0;
            c = 3;
            v=NULL;
        }

        vector(int n) {
            s = n;
            c = 3;
            v = new T[s];

            for (int x = 0; x < s; x++)
                v[x] = x;
            
            resize();
        }

        vector(vector<T> &other) {
            s = other.s;
            c = other.c;
            v = new T[s];

            for (int x = 0; x < s; x++)
                v[x] = other.v[x];
        }

        void operator=(vector<T> &other) {
            delete [] v;
            
            s = other.s;
            c = other.c;
            v = new T[s];

            for (int x = 0; x < s; x++)
                v[x] = other.v[x];
        }

        ~vector(){
            delete [] v;
        }

        int size() {
            return s;
        }

        int capacity() {
            return c;
        }

        T& operator[](int i) { //Only performs address arithmetic
            return (v[i]);
        }

        T& at(int i) {         //Check to make sure not out of bounds
            if (i >= s || i < 0)
                throw out_of_range("Out of bounds");
                
            return (v[i]);
        }

        void resize() {
            if (s > c) {
                T *temp = new T[c];
                
                for (int x = 0; x < c; x++)
                    temp[x] = v[x];
                
                delete [] v;
                v = temp;
                s = c;
            }
        }

        void push_back(T ele) {
            T *temp;
            temp = new T[++s];
            for(int i=0; i<s-1; i++)
                temp[i]=v[i];
            delete [] v;
            v=temp;
            v[s-1]=ele;
            resize();
        }
};