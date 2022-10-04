#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
  struct Race{
    int numberofLaps;
    int currentLaps;
    char nameWinner[20];
    char colorWinner[20];
  };
  struct RaceCar{
    char Name[20];
    char Color[20];
    int total;
  };
  
  void Welcome(struct RaceCar car1, struct RaceCar car2){
    printf(" Welcome everyone come to the Race between %s and %s!!!!\n Let's get started\n",car1.Name, car2.Name);

  }

  void Countdown(void){
    printf(" Get Started...\n 3\n 2\n 1    Start\n");
  }

  void CongLaps(struct Race *race){
    printf("Laps %d: %s in %s car is Winner!\n",race->currentLaps, race->nameWinner, race->colorWinner);
  }
  
  void Cong(struct Race *race){
     printf("And the Winner is %s in %s car!!!!!", race->nameWinner, race->colorWinner);
  }
  
  //logic function
  int cal(void){
    int speed=rand()%3+1;
    int boost=rand()%3+1;
    int neuron=rand()%3+1;
    int sum=speed+boost+neuron;
    return sum;
  }
  
  void updSpeed(struct RaceCar *car){
    car->total+=cal();
  }

  void updWiner(struct Race *race, struct RaceCar *car1, struct RaceCar *car2){
    if(car1->total>car2->total){
      strcpy(race->nameWinner,car1->Name);
      strcpy(race->colorWinner,car1->Color);
    }
    else{
      strcpy(race->nameWinner,car2->Name);
      strcpy(race->colorWinner,car2->Color);
    }
  }

  
  void Start( struct RaceCar *car1, struct RaceCar *car2){
     struct Race race={5,1,"",""};
     Welcome(*car1,*car2);
     Countdown();
     for(int i=0;i<race.numberofLaps;++i){
        updSpeed(car1);
        updSpeed(car2);
        updWiner(&race,car1,car2);
        CongLaps(&race);
        race.currentLaps+=1;
    }
        Cong(&race);
 }

  int main(){
    srand(time(NULL));
    struct RaceCar car1={"Mario","Red",'0'};
    struct RaceCar car2={"Luigi","Green",'0'};
    Start(&car1, &car2);
    return 0;
  }