#include <vector>
#include <cstdio>
#include <iostream>
typedef std::vector<std::vector<bool> > matrix;
typedef unsigned int uint;
/* Functions implement game logic 8 1 8 2 */
namespace Game {

    // Returns blank field where nobody is alive
    matrix *getBlankField(size_t rows, size_t cols) {
        matrix *field = new matrix();
        // Add rows... 
        for (uint a = 0; a < rows; a++) {
            field->push_back(std::vector<bool>());
            // ... and values into the row
            for (uint b = 0; b < cols; b++) {
                (field->at(a)).push_back(false);
            }
        }
        return field;
    }
    // Returns rows number
    size_t getRows(const matrix &field) {
        return field.size();
    }
    // Returns cols number
    size_t getCols(const matrix &field) {
        if (getRows(field) != 0) {
            return field[0].size();
        }
        return -1;
    }
void step(matrix &field)
{
    matrix *old = getBlankField(field.size(), field[0].size());

    for (uint i = 0; i < field.size(); i++) {
            for (uint j = 0; j < field[i].size(); j++) {               
                old->at(i).at(j) = field.at(i).at(j);
            }
        }
    matrix &oldField = *old;
    int i1, j1, x = 0;
    for ( uint i = 0; i < 20; i++)//2
      {
      for ( uint j = 0; j < 40; j++)//32
        {
         for ( int i0 = -1; i0 < 2; i0++)
           {
           for ( int j0 = -1; j0 < 2; j0++)
             {
             i1 = (i+i0+20)%20;//1 2 3
             j1 = (j+j0+40)%40;//31 32 33
             if (j1!=j||i1!=i){
             if (oldField[i1][j1])
                x++;//1
            }
             }
           }

        if (oldField[i][j])
         {
         if ( x == 2 || x == 3 )
          field[i][j] = true;
         else
            field[i][j] = false;
         }
        else
           {
           if ( x == 3 )
            field[i][j] = true;
           else
              field[i][j] = false;
           }
        x = 0;
        }
      }
}
void copy(matrix &field, matrix &oldField)
{
    for ( uint i = 0; i < 20; i++)
      {
      for ( uint j = 0; j < 40; j++)
        {
        oldField[i][j] = field[i][j];
        }
      }
}
bool isEqual(matrix &field, matrix &oldField)
{
if(field == oldField)return true;}

}
