#include<iostream>
#include<windows.h>
#include<conio.h>
#include<string.h>
using namespace std;
void gotoXY(short x,short y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void Hanger(){
	system("cls");
	int i;
	for(i=1;i<=8;i++){
		gotoXY(i+5,1);
		cout<<"-";
	}
	for(i=1;i<=24;i++){
		gotoXY(5,i);
		cout<<"|";
	}
	for(i=0;i<=11;i++){
		gotoXY(i,25);
		cout<<"-";
	}
	for(i=0;i<=4;i++){
		gotoXY(14,i+1);
		cout<<"|";
	}
	gotoXY(0,26);
}
void man(int p){
	switch(p){
		case 1:
			gotoXY(13,6);
			cout<<"***";
			gotoXY(12,7);
			cout<<"*****";
			gotoXY(12,8);
			cout<<"*****";
			gotoXY(13,9);
			cout<<"***";
			gotoXY(0,26);
			break;
		case 2:
			for(int i=0;i<2;i++){
				gotoXY(14,i+10);
				cout<<(char)19;
			}
			gotoXY(0,26);
			break;
		case 3:
			for(int i=0;i<4;i++){
				gotoXY(10+i,12);
				cout<<(char)174;
			}
			gotoXY(0,26);
			break;
		case 4:
			for(int i=0;i<4;i++){
				gotoXY(15+i,12);
				cout<<(char)175;
			}
			gotoXY(0,26);
			break;
		case 5:
			for(int i=0;i<4;i++){
				gotoXY(14,13+i);
				cout<<"#";
			}
			gotoXY(0,26);
			break;
		case 6:
			for(int i=0;i<4;i++){
				gotoXY(10+i,17);
				cout<<(char)174;
			}
			gotoXY(0,26);
			break;
		case 7:
			for(int i=0;i<4;i++){
				gotoXY(15+i,17);
				cout<<(char)175;
			}
			gotoXY(0,26);
			break;
	}
}
int belong(char word,char arr[]){
	for(int i=0;i<4;i++){
		if(arr[i]==word)
			return(1);
	}
	return(0);
}
int index(char word,char arr[]){
	int i;
	for(i=0;i<4;i++){
		if(arr[i]==word)
			break;
	}
	return(i);
}
main(){
	int i=0,r;
	char alpha;
	char warr[5];
	cout<<"\n\tPlayer 1\n\n\tEnter a four letter word : ";
	gets(warr);
	cout<<"\n\n\tPlayer 2 , Its your turn Now..........";
	getch();
	char rarr[]={'-','-','-','-'};
	Hanger();
	while(i!=7){
		gotoXY(0,26);
		cout<<"\n ";
		for(r=0;r<4;r++){
			cout<<rarr[r]<<" ";
		}
		cout<<"\n\nEnter an alphabet : ";
		cin>>alpha;
		if(belong(alpha,warr)){
			rarr[index(alpha,warr)]=alpha;
		}
		else{
			i++;
			man(i);
		}
		if(!strcmp(warr,rarr)){
			cout<<"\n  You Won";
			break;
		}
	}
	if(i==7){
		gotoXY(0,31);
		cout<<"\n  You Lost";
	}
	getch();
}
