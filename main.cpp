#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int main()
{
    int i = 0, n = 0, s, fanion, k;
    char cuv[10], a[10][10], aux[10], mesaj;
    fstream cit;
    mesaj = 'd';

    while (tolower(mesaj) == 'd'){
      cout << "Introduceti sirul: ";
      cin >> cuv;

      cit.open( "Strings.txt", ios::app);
      cit << cuv << endl;
      n++;
      cit.close();

      cout << "Mai introduceti date? (d/n) ";
      cin.ignore();
      cin >> mesaj;
    }
    cit.open("Strings.txt", ios::in);

    if(!cit.is_open()){
        cout << "Fisier inexistent: " << endl;
        return 0;
    }

    while(cit.good()){
        cit >> cuv;
        strcpy(a[i], cuv);
        i++;
    }

    cit.close();
    k = 0;

    do{
      fanion = 0;

      for(i = 0; i < n - 1 - k; i++){
         if(strcmp(a[i], a[i + 1]) > 0){
            strcpy( aux, a[i]);
            strcpy( a[i], a[i + 1]);
            strcpy( a[i + 1], aux);
            fanion = 1;
         }
      }
      k++;
    }
    while (fanion);

    for (i = 0; i < n; i++)
        cout << a[i] << " " << endl;
    return 0;
}
