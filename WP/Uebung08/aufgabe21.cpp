#include <iostream>
#include "mlcgXOR.hpp"
using namespace std;



void my_qsort(double *links, double *rechts) { //( zeiger auf ersten array-wert , Zeiger auf letzten array Wert)
   double *ptr1 = links; // übergabe der Zeiger auf temp Zeiger
   double *ptr2 = rechts;
   double w, x;
  
   x = *(links + ((rechts - links) >> 1)); // Gebe x den Wert der in der Mitte des arrays liegt
   do {
      while(*ptr1 < x) ptr1++; // ist der Wert von der im Zeiger1 kleiner als x wird der pointer nach rechts geschoben
      while(*ptr2 > x) ptr2--;// wie darüber bloß von links nach rechts
      if(ptr1 > ptr2) // Abrruch der do while schleife: der pointer1 liegt hinter pointer2
         break;
      w = *ptr1;  // tauschen der pointer Inhalte das *ptr1 >= *ptr2 durch die oberen whileschleifen 
      *ptr1 = *ptr2; 
      *ptr2 = w;
   } while(++ptr1 <= --ptr2);
   if(links < ptr2)  my_qsort(links, ptr2); 
   if(ptr1 < rechts) my_qsort(ptr1, rechts);
   // das ganze wird rekursiv weitergeführt und immer wenn eine größere Zahl vor einer kleineren liegt wird getauscht, bis das array in der richtigen Reihenfolge ist
}





int main() {
   double zufalls_array[100]; // array für die zufallszahlen
   Mlcgxor a(10199909); // irgendein startwert für die zufallszahlen


   for (int i = 1; i < 100; i++){ // füllen des arrays mit zufallszahlen nach mlcgxor im Intervall
   	   zufalls_array[i] =  a.intervall(-5. , 5. , i) ;
	  
	   
   }
 
   my_qsort(zufalls_array, zufalls_array + 100); // sortieren  
   
   for (int i = 0; i < 100; i++){ // ausgabe
   	   cout << zufalls_array[i] << "\t" << endl;
	}
	   

}