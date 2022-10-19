#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
   
   struct Race{
     char winner[20];
     char color_winner[20];
     int total_lap;
     int current_lap;
   };

   struct Race_Car{
     char name[20];
     char color[20];
     int mark;
   };
   
    /* PRINT PATH */ 
   void Welcome(struct Race_Car *race_car1, struct Race_Car *race_car2){
     fprintf(stdout,"Welcome everyone, Let's watch the race between %s in %s car and %s in %s car\n",race_car1->name,race_car1->color,race_car2->name,race_car2->color);
   }


   void coutdown(){
     fprintf(stdout,"The match begin in 3 2 1\n\tGo!!!!\n");
   }


   void Congratulation_lap(struct Race *race){
     fprintf(stdout,"Congratulation %s in %s car win lap %d\n", (*race).winner, (*race).color_winner, (*race).current_lap);
   }
   
   void Winner(struct Race *race){
    fprintf(stdout,"-\tTHE WINNER IS: %s in %s!!!!!",(*race).winner,(*race).color_winner);
   }

    // LOGICS PATH
   
   int random_mark(){
    int speed=rand()%1000+1;  // INCREASING % RANDOM
    int boost=rand()%1000+1;  // AND REDUCE MAXIMUM PERCENTAGE DRAW IN THE RACE
    int spirit=rand()%1000+1;
     int total=speed+boost+spirit;
      return total;
   }

   void update_mark(struct Race_Car *race_car1, struct Race_Car *race_car2){
    (*race_car1).mark=random_mark();
    (*race_car2).mark=random_mark();
   }

   void update_winner(struct Race *race, struct Race_Car *race_car1, struct Race_Car *race_car2){
    if((*race_car1).mark>(*race_car2).mark){
      strcpy((*race).winner,race_car1->name);
      strcpy((*race).color_winner,race_car1->color);
    }
    else if(race_car1->mark<race_car2->mark){
      strcpy(race->winner,race_car2->name);
      strcpy(race->color_winner,race_car2->color);
   }
  }

   void start_race(struct Race_Car *race_car1, struct Race_Car *race_car2){
      struct Race race={"","",5,1};
      Welcome(race_car1,race_car2);
      coutdown();
      for (int i = 0; i < 5; i++){
         update_mark(race_car1,race_car2);
         update_winner(&race,race_car1,race_car2);
         Congratulation_lap(&race);
         ++(race.current_lap);
      }
      Winner(&race);
    }
   
   int main(){
      srand(time(NULL));
      struct Race_Car race_car1={"Mario","Red",};
      struct Race_Car race_car2={"Luigi","Green",};
      start_race(&race_car1,&race_car2);
    return 0;
   }

    