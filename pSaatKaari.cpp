#include <iostream>

    int mostCommonElement(int arr[]){  
        int max = 0; 
        int commonElement; 
        for (int i = 0; i < 3; i++) { 
            int count = 0; 
            for (int j = 0; j < 3; j++) { 
                if (arr[i] == arr[j]) 
                    count++; 
            } 
            if (count > max) { 
                max = count; 
                commonElement = arr[i]; 
            } 
        } 
        return commonElement; 
    } 

int main(){
    
    int date,startM,startH,starTotalM,endM,endH,total=0,extra=0,deficit=0,badLate=0,goodLate=0,goodHaste=0,badHaste=0,avrage;
    int dates[4],startMs[4],startHs[4],endMs[4],endHs[4],totals[4];
    for (int i = 0; i < 4; i++)
    {
        std::cin>>date;
        dates[i]=date;
        std::cin>>startH>>startM;
        if (startM>60){
            startM-=60;
            startH++;
        }
        startMs[i]=startM;startHs[i]=startH;
        std::cin>>endH>>endM;
        if (endM>60){
            endM-=60;
            endH++;
        }
        endHs[i]=endH; endMs[i]=endM;

        starTotalM= startM+(startH*60);
        if (starTotalM<465 && startM>450){
            goodLate+=(starTotalM-450);
        }else if(starTotalM>465){
            badLate+=(starTotalM-450);
        }
        if (endM>15 && endM<30){
            goodHaste+=30-endM;
        }else if(endM<15){
            badHaste+=30-endM;
        }
        totals[i]=((endH*60)+endM)-((startH*60)+startM);
        total+=((endH*60)+endM)-((startH*60)+startM);
        if (total>480){
            extra+=(total-480);
        }else if(total<480){
            deficit+=(480-total);
        }
        system("CLS");
    }
    //-----------------------
        int upDate=dates[0];
        int max=totals[0];
        for(int i=0; i<4; i++ ){
            if(totals[i]>max){
                max=totals[i];
                upDate=dates[i];
            }
        }
        int lowDate=dates[0];
        int min=totals[0];
        for(int i=0; i<4; i++ ){
            if(totals[i]<min){
                min=totals[i];
                lowDate=dates[i];
            }
        }
        
    std::cout<<"most time start:  "<<mostCommonElement(startHs)<<":"<<mostCommonElement(startMs)<<'\n';
    std::cout<<"most time end:  "<<mostCommonElement(endHs)<<":"<<mostCommonElement(endMs)<<'\n';
    std::cout<<"extra:      "<<extra/60<<':'<<extra%60<<"\n";
    std::cout<<"badLate:    "<<badLate/60<<':'<<badLate%60<<"\n";
    std::cout<<"goodLate:   "<<goodLate/60<<':'<<goodLate%60<<"\n";
    std::cout<<"deficit:    "<<deficit/60<<':'<<deficit%60<<"\n";
    std::cout<<"goodHaste:  "<<goodHaste/60<<':'<<goodHaste%60<<"\n";
    std::cout<<"badHaste:   "<<badHaste/60<<':'<<badHaste%60<<"\n";
    std::cout<<"total:      "<<total/60<<':'<<total%60<<"\n";
    std::cout<<"avrage:     "<<(total/4)/60<<':'<<(total/4)%60<<"\n";
    std::cout<<"lowest worktime in day: "<<lowDate<<" with timework:     "<<min/60<<':'<<min%60<<"\n";
    std::cout<<"upest worktime in day: "<<upDate<<" with timework:     "<<max/60<<':'<<max%60<<"\n";
    return 0;
}