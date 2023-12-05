#include <iostream>
#include <unistd.h>

    //finds the usual element in array
    int mostCommonElement(int arr[]){  
        int max = 0; 
        int commonElement; 
        for (int i = 0; i < 30; i++) { 
            int count = 0; 
            for (int j = 0; j < 30; j++) { 
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
    //colors
    #define RESET   "\033[0m"
    #define YELLOW  "\033[33m"
    #define RED     "\033[31m"
    #define GREEN   "\033[32m"
    #define MAGENTA "\033[35m"
    #define CYAN    "\033[36m"
    #define BLUE    "\033[34m"
    #define GRAY    "\033[90m"
    #define WHITE   "\033[37m"
    #define LBLUE   "\033[94m"

int main(){
    //Initialize
    int n=30;
    int date,startM,startH,endM,endH,total=0,extra=0,deficit=0,badLate=0,goodLate=0,goodHaste=0,badHaste=0,avrage,month;
    //int startMs[n],startHs[n],endMs[n],endHs[n];
    int dates[n],totals[n],endTotalMs[n],startTotalMs[n];
    
    //cleans the terminal
    system("CLS");
    //waits for some secends
    usleep(200000);
    for (char c : "Enter the working month: ") {
        std::cout <<CYAN<< c<<RESET;
        usleep(20000);}
    //std::cout<<"Enter the working month: ";
    std::cin>>month;
    while(month<0 || month>12){
        //std::cout<<"The month you entered is not correct, try again: ";
        for (char c : "The month you entered is not correct, try again: ") {
            std::cout <<RED<< c<<RESET;
            usleep(20000);}
        std::cin>>month;
    }
    do
    {
        for (char c : "Enter the first day: ") {
            std::cout <<GREEN<< c<<RESET;
            usleep(20000);}
        std::cout<<month<<" / ";
        //std::cout<<"Enter the date: "<<month<<" / ";
        std::cin>>date;
    } while (date>30);
    system("CLS");

    for (int i = 0; i < n; i++){   
        usleep(200000);
        for (char c : "Today is the day: ") {
            std::cout <<GREEN<< c<<RESET;
            usleep(20000);}
        std::cout<<month<<" / "<<date<<"\n";
        dates[i]=date;
        date++;
        if (date+1>31)
        {
            month++;
            date=1;
        }
    //-----inputs start time----------------
        for (char c : "Enter the start time: ") {
        std::cout <<LBLUE<< c<<RESET;
        usleep(20000);}
        //std::cout<<"Enter the start time: ";
        std::cin>>startH>>startM;
        if (startM>60){
            startM-=60;
            startH++;
        }
        //startMs[i]=startM;startHs[i]=startH;
        
    //-----inputs end time----------------
        for (char c : "Enter the end time: ") {
            std::cout <<LBLUE<< c<<RESET;
            usleep(20000);}
        //std::cout<<"Enter the end time: ";
        std::cin>>endH>>endM;
        if (endM>60){
            endM-=60;
            endH++;
        }
        //endHs[i]=endH; endMs[i]=endM;

        startTotalMs[i]= startM+(startH*60);
        endTotalMs[i]= endM+(endH*60);

    //-----Allowed and not allowed delay-----------
        if(startH==7)
            if (startM<=45 && startM>30){
                goodLate+=(startM-30);
            }else if(startM>45){
                badLate+=(startM-30);
            }
    //-----Allowed and not allowed haste-----------    
        if(endH==15){
            if (endM>=15 && endM<30){
                goodHaste+=30-endM;
            }else if(endM<15){
                badHaste+=30-endM;
            }
        }
    //-----Calculation of work deficit and overtime--------------
        totals[i]=((endH*60)+endM)-((startH*60)+startM);
        total+=((endH*60)+endM)-((startH*60)+startM);
        if (totals[i]>480){
            extra+=(totals[i]-480);
        }else if(totals[i]<480){
            deficit+=(480-totals[i]);
        }
       system("CLS");
    }
    //-----Maximum working hours-----------
        int upDate=dates[0];
        int max=totals[0];
        for(int i=0; i<n; i++ ){
            if(totals[i]>max){
                max=totals[i];
                upDate=dates[i];
            }
        }
    //-----Minimum working hours---------------
        int lowDate=dates[0];
        int min=totals[0];
        for(int i=0; i<n; i++ ){
            if(totals[i]<min){
                min=totals[i];
                lowDate=dates[i];
            }
        }
//================outputs==================   
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';    
    //std::cout<<"most time start:  "<<mostCommonElement(startHs)<<":"<<mostCommonElement(startMs)<<'\n';
    for (char c : "Usual start time:   ") {
        std::cout << GREEN <<c<< RESET;
        usleep(2000);}
    std::cout<<mostCommonElement(startTotalMs)/60<<":"<<mostCommonElement(startTotalMs)%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
//------------------------------------
    // std::cout<<"most time end:  "<<mostCommonElement(endHs)<<":"<<mostCommonElement(endMs)<<'\n';
    for (char c : "Usual end time:   ") {
        std::cout <<GREEN<< c<<RESET;
        usleep(2000);}
    std::cout<<mostCommonElement(endTotalMs)/60<<":"<<mostCommonElement(endTotalMs)%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
//------------------------------------
    if (extra!=0)
    {
        // std::cout<<"extra:      "<<extra/60<<':'<<extra%60<<"\n";
        for (char c : "Total overtime hours:   "){
            std::cout <<CYAN<< c<<RESET;
            usleep(2000);}
        std::cout<<extra/60<<':'<<extra%60<<"\n";
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    }    
//----------------------------------
    if (badLate!=0)
    {
        // std::cout<<"badLate:    "<<badLate/60<<':'<<badLate%60<<"\n";
        for (char c : "Total not allowed delay in starting work:   "){
            std::cout <<RED<< c<<RESET;
            usleep(2000);}
        std::cout<<badLate/60<<':'<<badLate%60<<"\n";
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    }
//-------------------------------
    if (goodLate!=0)
    {
        // std::cout<<"goodLate:   "<<goodLate/60<<':'<<goodLate%60<<"\n";
        for (char c : "Total allowed delay in starting work:   ") {
            std::cout <<BLUE<< c<<RESET;
            usleep(2000);}
        std::cout<<goodLate/60<<':'<<goodLate%60<<"\n";
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    }    
//------------------------------------
    if (deficit!=0)
    {
        //std::cout<<"deficit:    "<<deficit/60<<':'<<deficit%60<<"\n";
        for (char c : "Total hours of work deduction:   ") {
            std::cout <<CYAN<< c<<RESET;
            usleep(2000);}
        std::cout<<deficit/60<<':'<<deficit%60<<'\n';
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    } 
//-------------------------------------
    if (goodHaste!=0)
    {
        //std::cout<<"goodHaste:  "<<goodHaste/60<<':'<<goodHaste%60<<"\n";
        for (char c : "Total allowed haste in end of work:   ") {
            std::cout <<BLUE<< c<<RESET;
            usleep(2000);}
        std::cout<<goodHaste/60<<':'<<goodHaste%60<<'\n';
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    }  
// ---------------------------------------------------
    if (badHaste!=0)
    {
        //std::cout<<"badHaste:   "<<badHaste/60<<':'<<badHaste%60<<"\n";
        for (char c : "Total not allowed haste in end of work:   ") {
            std::cout <<RED<< c<<RESET;
            usleep(2000);}
        std::cout<<badHaste/60<<':'<<badHaste%60<<'\n';
        std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
    }
// ------------------------------------
    //std::cout<<"total:      "<<total/60<<':'<<total%60<<"\n";
    for (char c : "Total working time:   ") {
        std::cout <<YELLOW<< c<<RESET;
        usleep(2000);}
    std::cout<<total/60<<':'<<total%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
// ----------------------------------
    //std::cout<<"avrage:     "<<(total/n)/60<<':'<<(total/n)%60<<"\n";
    for (char c : "Avrage working hours per day:   ") {
        std::cout <<GRAY<< c<<RESET;
        usleep(2000);}
    std::cout<<(total/n)/60<<':'<<(total/n)%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
// -------------------------------
    //std::cout<<"lowest worktime in day: "<<lowDate<<" with timework:     "<<min/60<<':'<<min%60<<"\n";
    for (char c : "Minimum working hours in day ") {
        std::cout <<MAGENTA<< c<<RESET;
        usleep(2000);}
    std::cout<<lowDate;
    for (char c : " with working hours:   ") {
        std::cout <<MAGENTA<< c<<RESET;
        usleep(2000);}
    std::cout<<min/60<<':'<<min%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
// ----------------------
    //std::cout<<"upest worktime in day: "<<upDate<<" with timework:     "<<max/60<<':'<<max%60<<"\n";
    for (char c : "Maximum working hours in day ") {
        std::cout <<MAGENTA<< c<<RESET;
        usleep(2000);}
    std::cout<<upDate;
    for (char c : " with working hours:   ") {
        std::cout <<MAGENTA<< c<<RESET;
        usleep(2000);}
    std::cout<<max/60<<':'<<max%60<<'\n';
    std::cout<<WHITE<<"--------------------------------------------------------------"<<RESET<<'\n';
//===========================================
    system("pause");
    return 0;
}