#include <string>
#include "Direction.hpp"
using  namespace std;
using  ariel::Direction;

namespace ariel{
    class Notebook {     
        public:
            Notebook();  
            void write(int page,int row,int ,Direction d, const string & data);
            string static read(int page,int row,int ,Direction d,int data);
            void erase(int page,int row,int ,Direction d,int data); 
            void show(int page);     
    };
}