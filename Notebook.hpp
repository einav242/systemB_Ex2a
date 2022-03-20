#include <string>
#include "Direction.hpp"
using  namespace std;
using  ariel::Direction;

namespace ariel{
    class Notebook {  
        // int page;
        // int line;
        // int colum;    
        public:
            Notebook();  
            void write(int page,int row,int ,Direction d,string data);
            string read(int page,int row,int ,Direction d,int data);
            void erase(int page,int row,int ,Direction d,int data); 
            void show(int page);     
    };
}