#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define MAXN 101
using namespace std;
struct coordinate{
        double x,z;
}loc[MAXN],res[MAXN*(MAXN-1)/2],circle;
double f[MAXN],radius=0;
int n,cnt;
const double pai=3.141592653589793;
coordinate calc(int i,int j){
        coordinate result;
        result.x=(loc[i].x*cos(f[i])*sin(f[j])-loc[j].x*sin(f[i])*cos(f[j])+(loc[i].z-loc[j].z)*sin(f[i])*sin(f[j]))/sin(f[j]-f[i]);
        result.z=(loc[j].z*cos(f[i])*sin(f[j])-loc[i].z*sin(f[i])*cos(f[j])-(loc[i].x-loc[j].x)*cos(f[i])*cos(f[j]))/sin(f[j]-f[i]);
        return result;
}
double get_distance(coordinate a,coordinate b){
        return sqrt(pow(a.x-b.x,2)+pow(a.z-b.z,2));
}
bool In_Cir(coordinate point){
        return get_distance(point,circle)<=radius+0.001;
}
coordinate solve(double A1,double B1,double C1,double A2,double B2,double C2){
        if(A1*B2-A2*B1==0) return circle;
        return (coordinate){(C1*B2-C2*B1)/(A1*B2-A2*B1),(A1*C2-A2*C1)/(A1*B2-A2*B1)};
}
void get_MinCir(){
        double temp;
        for(int i=1;i<=cnt;i++)
                if(!In_Cir(res[i])){
                        circle.x=res[i].x,circle.z=res[i].z,radius=0;
                        for(int j=1;j<i;j++)
                                if(!In_Cir(res[j])){
                                        circle.x=(res[i].x+res[j].x)/2.0,circle.z=(res[i].z+res[j].z)/2,radius=get_distance(res[i],circle);
                                        for(int k=1;k<j;k++)
                                                if(!In_Cir(res[k])){
                                                        circle=solve(2*(res[j].x-res[i].x),2*(res[j].z-res[i].z),pow(res[j].x,2)+pow(res[j].z,2)-pow(res[i].x,2)-pow(res[i].z,2),
                                                        2*(res[k].x-res[j].x),2*(res[k].z-res[j].z),pow(res[k].x,2)+pow(res[k].z,2)-pow(res[j].x,2)-pow(res[j].z,2));
                                                        radius=get_distance(circle,res[k]);
                                                }
                                        
                                }
                }
        
}
int main(){
        //freopen("stronghold.txt","r",stdin);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
                scanf("%lf%lf%lf",&loc[i].x,&loc[i].z,&f[i]);
                f[i]*=pai/180.0;
        }
        for(int i=1;i<=n;i++)
                for(int j=1;j<i;j++){
                        if(f[i]==f[j]) continue;
                        res[++cnt]=calc(i,j);
                }
        for(int i=1;i<=cnt;i++)
                printf("x=%.3lf,z=%.3lf\n",res[i].x,res[i].z);
        random_shuffle(res+1,res+cnt+1);
        get_MinCir();
        printf("\nThe final result is:\n");
        printf("x=%.3lf,z=%.3lf\nr=%.3lf\n",circle.x,circle.z,radius);
        system("pause");
}