#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//declearing an array to count number of sheats in  (20 X 5) cinemahalls
int seat_arr[20][5];

//for drawing line
void line(){
    for(int i=0;i<=100;i++){
        printf("=");
    }
    printf("\n");
}

//linked list for user details
struct node{
    char name[50];
    long long int mno;
    int seet;
    struct node *next;
};

//declearing all lists are impty initially
struct node *dctr[20][5]={NULL};

//for inserting details of user while booking ticket
struct node *insertend(struct node *ptr,int row,int clm){
    printf("Available sheats=%d\n", seat_arr[row][clm]);
    struct node *dnode=NULL;
    dnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Your Name:");
    fflush(stdin);
    gets(dnode->name);
    while(1){
        printf("Enter Your Mobile Number :+91 ");
        scanf("%lld", &dnode->mno);
        if(dnode->mno<=9999999999 && dnode->mno>=1000000000){
            break;
        }
        else{
            printf("Please enter a valid mobile number!!!\n");
        }
    }
    while(1){
        printf("Enter Number Of seets:");
        scanf("%d", &dnode->seet);
        seat_arr[row][clm]-=dnode->seet;
        if(dnode->seet==0){
            printf("enter valid number of sheets!!!");
        }
        else if(seat_arr[row][clm]<=0){
            printf("You have selected more seets!!!\n");
            seat_arr[row][clm]+=dnode->seet;
        }
        else{
            break;
        }
    }
    struct node *temp=ptr;
    if(ptr==NULL){
        ptr=dnode;
        dnode->next=NULL;
    }
    else{
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=dnode;
    dnode->next=NULL;
}
    line();
    printf(" ***THANK YOU*** \n");
    line();
    return ptr;
}
//for printing the list
void printlist(struct node *ctr){
    struct node *ptr=ctr;
    if(ctr!=NULL){
    printf("S.No.\tName\tMob.No.\t\tSeat\n");
    int i=1;
    while(ptr!=NULL){
        printf("%d\t%s\t%lld\t%d\n",i,ptr->name,ptr->mno,ptr->seet);
        i++;
        ptr=ptr->next;
    }
}
    else{
        printf("No Bookings!!!\n");
        line();
    }
}
//for cencillation
struct node *cancilation(struct node *ptr,int row,int clm){
    if(ptr==NULL){
        printf("you have selected wrong list, This list is empty!!!\n");
        return ptr;
    }
    long long int mnu;
    printf("Enter Your Mobile Number:+91 ");
    scanf("%lld",&mnu);
    int find_cstmr=0;
    struct node *temp1=ptr;
    while(temp1!=NULL){
        if(temp1->mno==mnu){
            find_cstmr=1;
            break;
        }
        temp1=temp1->next;
    }
    if(find_cstmr==0){
        printf("Sorry!!! You have selected wrong list\n");
        return ptr;
    }
    else{
        struct node *temp=ptr;
        if(temp->next==NULL){
            seat_arr[row][clm]+=temp->seet;
            free(temp);
            ptr=NULL;
            printf("*** CANCILLED ***\n");
            return ptr;
        }
        while(temp->next->mno!=mnu){
            temp=temp->next;
        }
        struct node *ppt=temp->next;
        seat_arr[row][clm]+=ppt->seet;
        if(temp->next->next==NULL){
            temp->next=NULL;
            free(ppt);
            printf("*** CANCILLED ***\n");
            return ptr;
        }
        temp->next=temp->next->next;
        free(ppt);
        printf("*** CANCILLED ***\n");
        return ptr;
        }
    }
//function for state
void state(){
    printf("S.No.\tState\n");
    printf("1.\tBihar\n2.\tRajasthan\n");

}
//function for district
void distrct(int dct){
    printf("S.No.\tDistrict\n");
    switch(dct){
        case(1):{
            printf("1.\tPatna\n2.\tEast Champaran\n3.\tDarbhanga\n4.\tGaya\n5.\tMuzaffarpur\n6.\tMadhubani\n7.\tKishanganj\n8.\tRohtas\n9.\tNalanda\n10.\tPurnia\n");
            break;
        }
        case(2):{
            printf("1.\tJaipur\n2.\tJodhpur\n3.\tKota\n4.\tBikaner\n5.\tAjmer\n6.\tUdaipur\n7.\tJaisalmer\n8.\tAlwar\n9.\tBhilwara\n10.\tSawai Madhopur\n");
            break;
        }
    }
}
//function for cinemahalls 
void cinemahall(int dct){
    switch(dct){
        case 1:{
            printf("1.\tINOX: City Centre Mall, Patna \n2.\tCinepolis: P&M Mall, Patna \n3.\tFun Cinemas: Regent Theatre \n4.\tINOX: Ashok, Patna \n5.\tConnplex Cinemas: S P Verma Road (JD Mall), Patna \n");
            break;
        }
        case 2:{
            printf("1.\tThe Cinema. 4.0609 Ratings. Kalyanpur Main Road Kalyanpur.\n2.\tRup Mahal Cinema.\n3.\tJanki Picture Palace.\n4.\tAnupam Picture Palace.\n5.\tPankaj Talkies. \n");
            break;
        }
        case 3:{
            printf("1.\tRajnish Complex : Darbhanga\n2.\tUVT sine Cafe : Darbhanga\n3.\tPrasad Chitralay : Darbhanga\n4.\tSahil Sinplex(Laheriyasarai)\n5.\tUma Picture Place(near CM science collage\n");
            break;
        }
        case 4:{
            printf("1.\tAPR cinemas(Rai kasinath More)\n2.\tAPR City Centre Mall(Swarajpuri mall)\n3.\tParadise cinema hall(Shaheeb Raod)\n4.\tRavi Cinema Hall(Rajauli Road Fatehpur)\n5.\tKishan Talkies(Bela Road Tekari)\n");
            break;
        }
        case 5:{
            printf("1.\tCinepolis Cinema(Club road Ramna)\n2.\tEylex Fun N Films(BB Collegiate Lane motijheel)\n3.\tJyoti Carnival(Amar Cinema Road Mithanpura)\n4.\tPJP Cinemas(Swami vivekanand Road Akharaghat)\n5.\tShyam Cinema(Motijheel Road Motijheel)\n");
            break;
        }
        case 6:{
            printf("1.\tLaxmi Talkies(state Highway 50)\n2.\tPratigya Theater(Bhagwanpur Road Madhepura)\n3.\tOM Cinema(Masjid Road)\n4.\tMansarowar Talkies(Khutauna Road)\n5.\tChitra Cinema(Harlakhi Road)\n");
            break;
        }
        case 7:{
            printf("1.\tIndra Talkies(Hospital Road Kisanganj Bazar)\n2.\tLaxmi Talkies(Station Rail Road Thakurganj)\n3.\tDiamond Cinema(National Highway 34 Dalkhola)\n4.\tLiberty Cinema(Rashokhowahat)\n5.\tPushpanjalee Cinema Hall(Dianjpur)\n");
            break;
        }
        case 8:{
            printf("1.\tSahu cinemax(Hetimpur)\n2.Anadi Theaters\t\n3.\tSahu cinemax(G T Road sasaram)\n4.\tJai Hind Talkies(Pali Road Dehri On Sona)\n5.\tShyam Cinema(State Highway 12 Bikramganj)\n");
            break;
        }
        case 9:{
            printf("1.\tKumar Cinema Hall(Shivaji Nagar Biharsarif)\n2.\tKisan Cinema Halls(Biharsharif)\n3.\tAjanta Cinema Hall(Main Road Biharsharif)\n4.\tVandana Talkies(Biharsharif)\n5.\tNaaz Cinema Hall(M G road Biharsharif)\n");
            break;
        }
        case 10:{
            printf("1.\tRoopbani Cinema(Mehboob khan Tola Purnia Court)\n2.\tJVR Plaza(Ford Company Road Gandhi)\n3.\tMithila Talkies(Aurahi Govindpur)\n4.\tRoopvani Movie(Mehboob Khan Tola Bhatta Bazar)\n5.\tFour Star Cinema(Mehboob Khan Tola Purnia)\n");
            break;
        }
        case 11:{
            printf("1.\tRaj Mandir Cinema\n2.\tINOX Cinemas (Element Mall)\n3.\tCinepolis Cinemas (Triton Mega Mall)\n4.\tEntertainment Paradise\n5.\tINOX Cinemas (Crystal Palm Mall)\n");
            break;
        }
        case 12:{
            printf("1.\tMiraj Cinemas, Jodhpur\n2.\tCarnival Cinemas Nasrani\n3.\tAirForce Cinema Hall\n4.\tInox Cinemas: Indiabulls Mega Mall\n5.\tNew Kohinoor cinema\n");
            break;
        }
        case 13:{
            printf("1.\tPVR Cinemall Kota\n2.\tCity Mall Fun Cinema Kota\n3.\tMayur Cinema\n4.\tGold Cinema, Kota\n5.\tOK CINEMAS:Natraj\n");
            break;
        }
        case 14:{
            printf("1.\tMovieMax Cinemas(Rani Bazar, Bikaner )\n2.\tCarnival Cinemas Cinemagic(Rani Bazar, Bikaner )\n3.\tDharma Old Cinema(Jaitpur, Bikaner)\n4.\tVandana Theather(Bidasar, Churu )\n5.\tChhotu Maharaj Cinema(Ladnun Road, Sujangarh)\n");
            break;
        }
        case 15:{
            printf("1.\tPlaza Cinema\n2.\tMiraj Bioscope Cinemas (Cine Mall)\n3.\tThe Crystal Park Cinema City Square Mall\n4.\tMridang Cinema\n5.\tINOX Cinemas (City Square Mall)\n");
            break;
        }
        case 16:{
            printf("1.\tAshoka Cinema(3 & 4, Panchsheel Marg, Udaipur)\n2.\tINOX Cinemas(Lake City Mall, Main Road, Ashok Nagar)\n3.\tPicture Palace Cinema(Udaipur City)\n4.\tMiraj Cinema (Miraj Meridian Mall)(5th Floor, Nathuwas Road, Nathdwara Chaupati, Nathdwara)\n5.\tPVR Cinemas (Nexus Celebration)(Nexus Celebration, Udaipur City)\n");
            break;
        }
        case 17:{
            printf("1.\tRamesh Talkies(Hanuman Chowk, Jaisalmer)\n2.\tLatiyal Talkies(Phalodi)\n3.\tAshish Inox Multiplex(Dholabala Harijan Basti, Phalodi)\n4.\tConnplex Cinemas(Balotra)\n5.\tGlitz Cinemas(Jalore)\n");
            break;
        }
        case 18:{
            printf("1.\tGold Digital Cinema (Cross Point Mall)(Alwar Ho, Alwar)\n2.\tParv Plaza(Industrial Area, Alwar)\n3.\tTopp Notch Digital Cinema(Indra Colony, Alwar)\n4.\tM4miniplex(Behror, Alwar)\n5.\tGold Gopal Cinema(Kabir Colony, Alwar)\n");
            break;
        }
        case 19:{
            printf("1.\tINOX Cinemas (City Centre Mall)(Bhopal Ganj, Bhilwara)\n2.\tINOX Cinemas (Reliance Mall)(azad nagar, Bhilwara)\n3.\tMiraj Bioscope Cinemas(Subhash Nagar, Bhilwara)\n4.\tOk Cinemas(Shahpura Bhilwara, Bhilwara)\n5.\tCineplus Cinema(Bijainagar)\n");
            break;
        }
        case 20:{
            printf("1.\tPrakash Talkies( Sawai Madhopur Ho)\n2.\tKailash Talkies(Gangapur)\n3.\tSuraj Cinema(Sawai Madhopur Ho)\n4.\tKrishna Talkies(Sheopur Ho)\n5.\tGeeta Talkies(Hindaun City, Hindaun)\n");
            break;
        }
    }
}
int main(){
    int ste,dct,cnhl,set=50,ilp=1;
    //declearing all cinemahalls contain 50 sheets initially
    for(int i=0;i<20;i++){
        for(int j=0;j<5;j++){
            seat_arr[i][j]=50;
        }
    }
    while(ilp==1){
        int choice;
        printf("press\n1.for Booking Ticket\n2.for View List of Bookings\n3.for cancellation\n4.for exit: ");
        scanf("%d", &choice);
        line();
        if(choice==4){
            printf("                                       ***THANK YOU***\n");
            line();
            break;
        }
        else if(choice==1){
            printf("!!!   Welcome To Cinema Hall Ticket Bookong System   !!!\n");
            printf("Select your state\n");
            state();
            while(1){
                printf("Enter Serial Number : ");
                scanf("%d", &ste);
                line();
                if(ste<=2 && ste>=1){
                    printf("Select Your District\n");
                    distrct(ste);
                    while(1){
                        printf("Enter Serial Number : ");
                        scanf("%d", &dct);
                        line();
                        if(dct>=1 && dct<=10){
                            cinemahall(dct+10*(ste-1));
                            while(1){
                                printf("Enter Serial Number : ");
                                scanf("%d", &cnhl);
                                line();
                                if(cnhl>=1 && cnhl<=5){
                                    dctr[(ste-1)*10+dct-1][cnhl-1]=insertend(dctr[(ste-1)*10+dct-1][cnhl-1],(ste-1)*10+dct-1,cnhl-1);
                                    break;
                                }
                                else{
                                    printf("please enter a valid serial number!!!\n");
                                }
                            }
                            break;
                        }
                        else{
                            printf("please enter a valid serial number:\n");
                        }
                    }
                break;
                }
                else{
                    printf("please enter a valid serial number!!!\n");
                }
            }

        }
        else if(choice==2){
            printf("Select your state\n");
            state();
            while(1){
                printf("Enter Serial Number : ");
                scanf("%d", &ste);
                line();
                if(ste<=2 && ste>=1){
                    printf("Select Your District\n");
                    distrct(ste);
                    while(1){
                        printf("Enter Serial Number : ");
                        scanf("%d", &dct);
                        line();
                        if(dct>=1 && dct<=10){
                            cinemahall(dct+10*(ste-1));
                            while(1){
                                printf("Enter Serial Number : ");
                                scanf("%d", &cnhl);
                                line();
                                if(cnhl>=1 && cnhl<=5){
                                    printlist(dctr[(ste-1)*10+dct-1][cnhl-1]);
                                    line();
                                    break;
                                }
                                else{
                                    printf("please enter a valid serial number!!!\n");
                                }
                            }
                            break;
                        }
                        else{
                            printf("please enter a valid serial number:\n");
                        }
                    }
                break;
                }
                else{
                    printf("please enter a valid serial number!!!\n");
                }
            }

        }
        else if(choice==3){
            printf("!!!   Welcome To Cinema Hall Ticket Cancillation System   !!!\n");
            printf("Select your state\n");
            state();
            while(1){
                printf("Enter Serial Number : ");
                scanf("%d", &ste);
                line();
                if(ste<=2 && ste>=1){
                    printf("Select Your District\n");
                    distrct(ste);
                    while(1){
                        printf("Enter Serial Number : ");
                        scanf("%d", &dct);
                        line();
                        if(dct>=1 && dct<=10){
                            cinemahall(dct+10*(ste-1));
                            while(1){
                                printf("Enter Serial Number : ");
                                scanf("%d", &cnhl);
                                line();
                                if(cnhl>=1 && cnhl<=5){
                                    dctr[(ste-1)*10+dct-1][cnhl-1]=cancilation(dctr[(ste-1)*10+dct-1][cnhl-1],(ste-1)*10+dct-1,cnhl-1);
                                    line();
                                    break;
                                }
                                else{
                                    printf("please enter a valid serial number!!!\n");
                                }
                            }
                            break;
                        }
                        else{
                            printf("please enter a valid serial number:\n");
                        }
                    }
                break;
                }
                else{
                    printf("please enter a valid serial number!!!\n");
                }
            }
        }
        else{
            printf("Invalid Choice!!!\nplease enter a valid choice!!!\n");
        }
    }
    return 0;
}