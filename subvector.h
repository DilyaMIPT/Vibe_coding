struct subvector { 
    int *data;
    unsigned int size;
    unsigned int capacity; 
};
bool init(subvector *vec);
bool resize(subvector* vec, unsigned int new_capacity);
bool push_back(subvector *vec, int element);
int pop_back(subvector* vec);
void shrink_to_fit(subvector* vec) ;
void clear(subvector *vec);
void destructor(subvector *vec);