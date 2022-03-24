#include <cstddef>
    
    template <typename T>
    struct Set {
        T* data;
        int size;        
        int count;
    };
	
    template <typename T>
    void initialize(Set<T>& set){
        set.data = new T[2];
        set.size = 2;
        set.count = 0;
    }
    
    template <typename T>
    void destroy(Set<T>& set){
        delete[] set.data;
        set.data = NULL;
        set.size = 0;
        set.count = 0;
    }
    
    template <typename T>
    bool isEmpty(Set<T> set){
        return set.count == 0;
    }
    
    template <typename T>
    void insert(Set<T>& set, T value){
        for(int i = 0; i < set.count; i++)
            if(set.data[i] == value)
                return;

        if(set.count == set.size){
            T* newData;
            T* tempData;

            int tempSize = set.size;
            
            set.size *= 2;

            tempData = set.data;
            newData = new T[set.size];

            for(int i = 0; i < set.size; i++)
                newData[i] = tempData[i];
            
            set.data = newData;

            delete[] tempData;
            tempData = NULL;
        }

        set.data[set.count++] = value;
    }
    
    template <typename T>
    bool contains(Set<T> set, T value){
        for(int i = 0; i < set.count; i++)
            if(set.data[i] == value)
                return true;
        return false;
    }
    
    template <typename T>
    void remove(Set<T>& set, T value){
        for(int i = 0; i < set.count; i++)
            if(set.data[i] == value)
                set.data[i] = set.data[--set.count];
    }
    
    template <typename T>
    int  getSize(Set<T> set){
        return set.count;
    }