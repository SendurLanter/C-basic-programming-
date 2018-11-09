//================================================================
//  PROGRAMMER : "許智和"
//  DATE                   : 2016-11-26
//  FILENAME         : HW05AB05611040.CPP
//  DESCRIPTION   :  simulate game
//================================================================

#include<iostream>
using namespace std;
int answer1;
int answer2;
int answer3;

int main(){

bool simulation[20][20];  //細胞方陣,
int n;  //generatino數

for(int i=0;i<20;i++){   //初始化, 歸零
    for(int j=0;j<20;j++){
        simulation[i][j]=false;}
}

/*for(int w=0;w<400;w++){  //input陣列中存在活細胞的座標
int x,y; //,活細胞座標用變數
cout<<"plz input live cell's x and negative number for leave"<<endl;
cin>>x;
if(x<0){
break;
}
cout<<"plz input live cell's y and negative number for leave"<<endl;
cin>>y;
if(y<0){
break;
}
simulation[y-1][x-1]=true;   //有活細胞則為1
}*/
for(int w=0;w<20;w++){
    for(int t=0;t<20;t++){
        cin>>simulation[w][t];
    }
}

cin>>n;   //generation數

for(int k=0;k<n;k++){  //generation次數

    int ans=0; // answer123用途
    int store1[400][2];  //存這局中live cell
    int store2[400][2];  //存這局中dead cell
    int cal=0;  //store1編號用變數
    int call=0; //store2編號用變數

    for(int i=0;i<20;i++){   //輸出目前世代的細胞狀況
        for(int j=0;j<20;j++){
            if(simulation[i][j]==1){
            ans++;   //數細胞數
            }
        cout<<simulation[i][j]<<"  ";
    }
        cout<<"\n";
    }

    if(k==0){    //題目要求
    answer1=ans;
    }
    else if(k==1){
    answer2=ans;
    }
    else if(k==2){
    answer3=ans;
    }

    for(int m=0;m<20;m++){   //九宮格判斷
        for(int h=0;h<20;h++){
            int a=0;
            if(m==0&&h>0){     //邊界情況
                a=simulation[m][h-1]+simulation[m][h+1]
                   +simulation[m+1][h-1]+simulation[m+1][h]+simulation[m+1][h+1];
            }
            else if(h==0&&m>0){   //邊界情況
                a=simulation[m-1][h]+simulation[m-1][h+1]
                   +simulation[m][h+1]
                   +simulation[m+1][h]+simulation[m+1][h+1];//周圍8個數的值
            }
            else if(h==0&&m==0){  //邊界情況(一個點)
                a=simulation[m][h+1]
                   +simulation[m+1][h]+simulation[m+1][h+1];//周圍8個數的值
            }
            else if(m==19&&h!=19){  //邊界情況
                a=simulation[m-1][h-1]+simulation[m-1][h]+simulation[m-1][h+1]//周圍8個數的值
                   +simulation[m][h-1]+simulation[m][h+1];
            }
            else if(h==19&&m!=19){  //邊界情況
                a=simulation[m-1][h-1]+simulation[m-1][h]//周圍8個數的值
                   +simulation[m][h-1]
                   +simulation[m+1][h-1]+simulation[m+1][h];
            }
            else if(h==19&&m==19){  //邊界情況(一個點)
                a=simulation[m-1][h-1]+simulation[m][h-1]+simulation[m-1][h];
            }
            else{
            a=simulation[m-1][h-1]+simulation[m-1][h]+simulation[m-1][h+1]//周圍8個數的值
                   +simulation[m][h-1]+simulation[m][h+1]
                   +simulation[m+1][h-1]+simulation[m+1][h]+simulation[m+1][h+1];
            }

            if(simulation[m][h]==1){ //if this cell is alive

                if(a<2||a>3){   //cell -> dead 的遊戲規則
                    store1[cal][0]=m;   //將此cell's座標先存入陣列以後計算以便後續計算
                    store1[cal][1]=h;
                    cal++;  //數這局有幾個要死(給for用的)
                   }
            }
            else{
                if(a==3){  //cell -> live 的遊戲規則
                    store2[call][0]=m;  //將此cell's座標先存入陣列以後計算以便後續計算
                    store2[call][1]=h;
                    call++;  //數這局有幾個要活(給for用的)
                    }
            }
        }
    }

for(int o=0;o<cal;o++){
    simulation[store1[o][0]][store1[o][1]]=false;  //上面存的座標套入  使這細胞死亡
    }
for(int O=0;O<call;O++){
    simulation[store2[O][0]][store2[O][1]]=true;  //上面存的座標套入  使這細胞復活
    }
cout<<"\n";
}
return 0;
}

