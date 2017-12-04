//UID-3035392177 NAME- Tanwar Abhimanyue Singh
#include <iostream>
using namespace std;
//global variables
int sizeofmaze;
int nitem;
struct mazeitem{
string type;
string direction;
int x;
int y;
};
struct destindex{
int index;
int dx; int dy;
};
//global arrays
mazeitem items[20]; mazeitem temp; mazeitem itemslist[20]; mazeitem firstelement; destindex dlist[5];
//function declarations
void dfinder();
void ofn();
void ofs();
void ofe();
void ofw();

void ofn()
{ int j=0; int ctr=0;
   for(int i=0;i<nitem;i++)
   { if((items[i].x == temp.x) && (items[i].y != temp.y) && (items[i].y > temp.y))
       {itemslist[j]=items[i]; j++;
         ctr++;
       } }
       if(ctr == 0)
       { temp.y = (sizeofmaze+1);
       }
       else{
       firstelement = itemslist[0];
       for(int k=1 ; k<ctr ; k++)
       {if(itemslist[k].y<firstelement.y)
            firstelement = itemslist[k];
       }
       if(firstelement.type == "single")
           {if(firstelement.direction == "ne")
           {temp.y = firstelement.y;}
        else if(firstelement.direction == "nw")
           {temp.y = firstelement.y;
           }
        else if(firstelement.direction == "se")
            {temp.y = firstelement.y; ofe();
            }
            else
            {temp.y = firstelement.y;
                ofw();
            } }
           else if(firstelement.type == "double")
         { if(firstelement.direction == "nw" || firstelement.direction == "se")
         {temp.y = firstelement.y; ofe();
         }
         else if(firstelement.direction == "ne" || firstelement.direction == "sw")
         {temp.y = firstelement.y;
          ofw();
         }}
         else if(firstelement.type == "block")
         {temp.y = firstelement.y;
         }

         else if(firstelement.type == "dest")
         {
             temp.y = firstelement.y;
         }
         else if(firstelement.type == "source")
         { if(firstelement.y>temp.y)
            { temp.y = firstelement.y;
             }
             else
            { temp.y = (sizeofmaze+1);
             } }}}


         void ofs()
{
   int j=0; int ctr=0;
   for(int i=0  ; i<nitem ; i++)
   {if((items[i].x == temp.x) && (items[i].y != temp.y) && (items[i].y < temp.y))
       {itemslist[j]=items[i];
         j++;
         ctr++;
       } }
       if(ctr == 0)
       { temp.y = (sizeofmaze+1);
       }
       else { firstelement= itemslist[0];
       for(int k=1 ; k<ctr ; k++)
       {
           if(itemslist[k].y>firstelement.y)
           firstelement = itemslist[k];
       }


    if(firstelement.type == "single")
           {if(firstelement.direction == "se")
           {temp.y = firstelement.y;
           }
           else if(firstelement.direction == "sw")
           {temp.y = firstelement.y;
           }
            else if(firstelement.direction == "ne")
            {temp.y = firstelement.y;
            ofe();
            }
            else
            {temp.y = firstelement.y;
            ofw(); }}
     else if(firstelement.type == "double")
         { if(firstelement.direction == "nw" || firstelement.direction == "se")
         {temp.y = firstelement.y;
             ofw();
         }
         else if(firstelement.direction == "ne" || firstelement.direction == "sw")
         {temp.y = firstelement.y;
          ofe();
         } }
    else if(firstelement.type == "block")
         {
             temp.y = firstelement.y;
         }
    else if(firstelement.type == "dest")
         {
             temp.y = firstelement.y;}
else if(firstelement.type == "source")
         {   if(firstelement.y>temp.y)
         {temp.y = (sizeofmaze+1);
        }
         else
            { temp.y = firstelement.y;
            } } } }

        void ofe()

{
int j=0; int ctr=0;
   for(int i=0 ; i<nitem ; i++)
   { if((items[i].y == temp.y) && (items[i].x > temp.x))
       {
         itemslist[j]=items[i];
         j++;
         ctr++; } }

if(ctr == 0)
{
    temp.x = (sizeofmaze+1);
}
      else {firstelement = itemslist[0];
       for(int k=1 ; k<ctr ; k++)
       {
           if(itemslist[k].x<firstelement.x)
           {
           firstelement = itemslist[k];} }

          if(firstelement.type == "single")
           {if(firstelement.direction == "se")
           {
               temp.x = firstelement.x;
           }
           else if(firstelement.direction == "sw")
           {
               temp.x = firstelement.x; ofs();
           }
            else if(firstelement.direction == "ne")
            { temp.x = firstelement.x;
            }
            else
            {temp.x = firstelement.x; ofn();
            }
           }
         else if(firstelement.type == "double")
         { if(firstelement.direction == "nw" || firstelement.direction == "se" )
         {temp.x = firstelement.x;
         ofn();
         }
         else if(firstelement.direction == "ne" || firstelement.direction == "sw")
         {temp.x = firstelement.x;ofs();
         }}
         else if(firstelement.type == "block")
         {
           temp.x = firstelement.x;}
         else if(firstelement.type =="dest")
         {
             temp.x = firstelement.x;}
         else if(firstelement.type == "source")
         {
            if(firstelement.x<temp.x)
            {temp.x = (sizeofmaze+1);
              }

            else{temp.x = firstelement.x;
             } }}}
void ofw()
{  int j=0; int ctr=0;
   for(int i=0  ; i<nitem ; i++)
   {
       if((items[i].y == temp.y) && (items[i].x != temp.x) && (items[i].x < temp.x))
       {
         itemslist[j]=items[i];
         j++;
         ctr++;
       } }
       if(ctr == 0)
{temp.x = (sizeofmaze+1);
}
else { firstelement = itemslist[0];
       for(int k=1 ; k<ctr ; k++)
       {if(itemslist[k].x>firstelement.x)
            firstelement = itemslist[k];
       }
       if(firstelement.type == "single")
           {if(firstelement.direction == "se")
           {
               temp.x = firstelement.x;
               ofs();
           }
           else if(firstelement.direction == "sw")
           {
               temp.x = firstelement.x;

           }
            else if(firstelement.direction == "ne")
            {
                temp.x = firstelement.x;
                ofn();

            }
            else
            {
                temp.x = firstelement.x;
            } }
       else if(firstelement.type == "double")
         { if(firstelement.direction == "nw" || firstelement.direction == "se")
         {
             temp.x = firstelement.x;
             ofs();}
         else if(firstelement.direction == "ne" || firstelement.direction == "sw")
         {
             temp.x = firstelement.x;
             ofn(); } }
       else if(firstelement.type == "block")
         {temp.x = firstelement.x;
         }
      else if(firstelement.type =="dest")
         {temp.x = firstelement.x;
         }
         else if(firstelement.type == "source")
         {if(firstelement.x>temp.x)
         {temp.x = (sizeofmaze+1);
             }
           else
            { temp.x = firstelement.x;
            }}
        else
         {temp.x = (sizeofmaze+1);} } }

void dfinder()
{ if(temp.direction == "north")
   ofn();
        else if(temp.direction == "south")
        ofs();
        else if(temp.direction == "east")
       {
    ofe();
      }
        else if(temp.direction == "south")
        ofs();
        else
        ofw();
        }

//main function
int main(){
cin>>sizeofmaze;
cin>>nitem;
//variables in main
char ch; int j=0;

for(int i=0; i<nitem ; i++)
{
    cin>>items[i].type;
    if(items[i].type == "dest")
    {
        items[i].direction = "null";
        cin>>items[i].x>>ch>>items[i].y;
        dlist[j].dx = items[i].x;
        dlist[j].dy = items[i].y;
        dlist[j].index = (j+1);
        j++;
    }
else if(items[i].type == "block")
{
   items[i].direction = "null";
        cin>>items[i].x>>ch>>items[i].y;
}
    else
    {
        cin>>items[i].direction>>items[i].x>>ch>>items[i].y;
    }
}




for(int j=0 ; j<nitem ; j++)
{
    if(items[j].type == "source")
    {
       temp = items[j];
        dfinder();
        items[j]=temp;

    }

}
int b =1;
for(int k=0 ; k<nitem ; k++)
{ int ctr =0;
    if(items[k].type=="source")
    {
        for(int a=0 ; a<j ; a++)
        {
            if((items[k].x == dlist[a].dx) && (items[k].y == dlist[a].dy))
            {
                cout<<b<<'-'<<dlist[a].index<<endl;
                 ctr++;
            }
        }
        if(ctr == 0)
        {
            cout<<b<<'-'<<'x'<<endl;
        }
        b++;
    } }
return 0;
}
