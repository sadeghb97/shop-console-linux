#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BOLDRED     "\033[1m\033[31m"
#define RESETC   "\x1b[0m"
struct date{
	int y;
	int m;
	int d;
};
struct food{
	int id;
	char name[30];
	char com[30];
	int cost;
	int sort;
	struct date date;
};
int menu(void);
void add(struct food *,struct food *,int);
void show(struct food *,int);
void savefile(struct food *,int);
void save (struct food *,struct food*,int);
void load (struct food *,struct food *,int);
void printfood (struct food *,int);
int searcharray(char[],char[]);
void search(struct food *,int);
int randid(struct food *,struct food *,int);
void reclyce (struct food *,struct food *,int);
void strcopy (char[],char[]);
void deletefood (struct food *, struct food *, int);
void upfood (struct food *,int);
void showsort(struct food *,int);
int main(){
	struct food *f,*del;
	int m,choice;
	printf("lotfan tedade Maximume kala ha ra vared konid =");
	scanf("%d",&m);
	f=malloc(m * sizeof(struct food));
	del=malloc(200 * sizeof(struct food));
	for (int a=0;a<m;a++) f[a].id=0;
	for (int a=0;a<200;a++) del[a].id=0;	
	while (1){
		choice=menu ();
		switch(choice){
			case 1: show(f,m); break;
			case 2: search(f,m); break;
			case 3: upfood(f,m); break;
			case 4: add(f,del,m); break;
			case 5: showsort(f,m); break;
			case 6: savefile(f,m); break;
			case 7: save(f,del,m); break;
			case 8: load(f,del,m); break;
			case 9: deletefood(f,del,m); break;
			case 10: reclyce(del,f,m); break;			
			case 11: exit(0); break;
		}
	}
return 0;
}
void add(struct food *a,struct food *b,int m){
	int t,i,j,anjam=1;
	printf ("\nChe tedad kala ra aknun vared mikonid? \n");
	scanf ("%d" ,& t);
	for(i=0; a[i].id !=0 && m>i; i++);
	if (i==m && a[i].id!=0){
		printf("List kamelan por ast.\n");
		anjam=0;
	}
	if (m-i<t && anjam==1){
		printf ("List zarfiate in tedad kala ra nadarad. \n");
	}
	else if(anjam==1){
		for(j=0; t>j; j++,i++){
			printf("\nID kala:\n");
			a[i].id=randid(a,b,m);
			printf("%d\n",a[i].id);
			printf("lotfan name kala ra vared konid :\n");
			scanf("%s",a[i].name);
			printf("lotfan name sherkat sazande ra vared konid :\n");
			scanf("%s",a[i].com);
			printf("lotfan gheymate kala ra vared konid :\n");
			scanf("%d",&a[i].cost);
			printf("lotfan be tartib sal/mah/rooz tarikh engheza ra vared konid :\n");
			scanf("%d%d%d",&a[i].date.y,&a[i].date.m,&a[i].date.d);
		}
	}
}
void show (struct food *a,int m){
	int i;
	for (i=0; a[i].id!=0 && m>i; i++){
		if (i==0) printf("\nListe kalahaye forushgah:\n");
		printf ("\nKalaye %d: \n",i+1);
		printf ("ID: %d\n",a[i].id);
		printf ("Name: %s\n",a[i].name);
		printf ("Company: %s\n",a[i].com);
		printf ("Cost: %d\n",a[i].cost);
		printf ("Tarikhe Engheza: %d/%d/%d\n",a[i].date.y,a[i].date.m,a[i].date.d);
	}
	if (i==0) printf ("\nHich kalaei ezafe nashode ast.\n");
}
int menu(void){
	int choice;
	printf (BOLDRED "\nMenu: \n" RESETC);
	printf("1: Show\n2: Search \n3: Update \n4: Add \n5: Sort \n6: Save in a file \n7: Save \n8: Load Shop\n9: Delete \n10: Reclyce Bin\n11: Exit\n");
	printf ("\nEnter your choice: \n");
	scanf ("%d" ,& choice);
	while(choice<1 || choice>11){
		printf ("\nNa motabar.\n");
		printf ("Enter your choice: \n");
		scanf ("%d" ,& choice);
	}
	return choice;
}
void savefile(struct food *a,int m){
	int i;
	FILE *fp;
	fp=fopen("foods.txt","wt");
	for (i=0; a[i].id!=0 && m>i; i++){
		fprintf (fp,"\nKalaye %d: \n",i+1);
		fprintf (fp,"ID: %d\n",a[i].id);
		fprintf (fp,"Name: %s\n",a[i].name);
		fprintf (fp,"Company: %s\n",a[i].com);
		fprintf (fp,"Cost: %d\n",a[i].cost);
		fprintf (fp,"Tarikhe Engheza: %d/%d/%d\n",a[i].date.y,a[i].date.m,a[i].date.d);
	}
	fclose(fp); fp=0;
	printf ("Saved in a file !!!\n");
}	
void save (struct food *a,struct food *b,int m){
	FILE *fp; fp=0;
	int t,i;
	fp= fopen("forushgah.txt","wt");
	for(t=0; a[t].id!=0 && m>t; t++);
	fprintf(fp,"%d\n",t);
	for(i=0; t>i; i++){
		fprintf(fp,"%d\n",a[i].id);
		fprintf(fp,"%s\n",a[i].name);
		fprintf(fp,"%s\n",a[i].com);
		fprintf(fp,"%d\n",a[i].cost);
		fprintf(fp,"%d\n%d\n%d\n",a[i].date.y,a[i].date.m,a[i].date.d);
	}
	for(t=0; b[t].id!=0 && 200>t; t++);
	fprintf(fp,"%d\n",t);
	for(i=0; t>i; i++){
		fprintf(fp,"%d\n",b[i].id);
		fprintf(fp,"%s\n",b[i].name);
		fprintf(fp,"%s\n",b[i].com);
		fprintf(fp,"%d\n",b[i].cost);
		fprintf(fp,"%d\n%d\n%d\n",b[i].date.y,b[i].date.m,b[i].date.d);
	}
	fclose(fp); fp=0;
	printf ("Shop Saved !!!\n");
}
void load (struct food *a,struct food *b,int m){
	FILE *fp;
	int t,i;
	fp=fopen("forushgah.txt","rt");
	fscanf(fp,"%d",&t);
	if (t>m) printf("Gonjayeshe Maximum kafi nist. file nemitavanad load shavad.\n");
	else{
		for(i=0; t>i; i++){
			fscanf(fp,"%d",& a[i].id);
			fscanf(fp,"%s",a[i].name);
			fscanf(fp,"%s",a[i].com);
			fscanf(fp,"%d",&a[i].cost);
			fscanf(fp,"%d%d%d",&a[i].date.y,&a[i].date.m,&a[i].date.d);
		}
		for(; a[i].id!=0 && m>i; i++) a[i].id=0;
		fscanf(fp,"%d",&t);
		for(i=0; t>i; i++){
			fscanf(fp,"%d",& b[i].id);
			fscanf(fp,"%s",b[i].name);
			fscanf(fp,"%s",b[i].com);
			fscanf(fp,"%d",&b[i].cost);
			fscanf(fp,"%d%d%d",&b[i].date.y,&b[i].date.m,&b[i].date.d);
		}
		for(; b[i].id!=0 && 200>i; i++) b[i].id=0;	
		printf("Shop Loaded !!!\n");	
	}	
}
void printfood (struct food *a,int i){
	printf ("ID: %d\n",a[i].id);
	printf ("Name: %s\n",a[i].name);
	printf ("Company: %s\n",a[i].com);
	printf ("Cost: %d\n",a[i].cost);
	printf ("Tarikhe Engheza: %d/%d/%d\n",a[i].date.y,a[i].date.m,a[i].date.d);
}
int searcharray(char a[],char b[]){
	int n1,n2,i,i1,i2,check=0;
	for (n1=0; a[n1]!=0; n1++);
	for (n2=0; b[n2]!=0; n2++);
	for (i=0; n1-n2>=i; i++){
		if(b[0]==a[i] || b[0]==(a[i]+32) || b[0]==(a[i]-32)){
			check=1;
			for(i2=1,i1=i+1; n2>i2 && check==1; i1++,i2++) if(b[i2]!=a[i1] && b[i2]!=(a[i1]+32) && b[i2]!=(a[i1]-32)) check=0;
			if (check==1) return check;
		}
	}
	return 0;
}
void search(struct food *a,int m){
	int yaft[100],t=0,i=0;
	char s[100];
	printf("\nEbarati ke mikhahid search konid ra vared konid:\n");
	scanf("%s",s);
	for(i=0; a[i].id!=0 && m>i; i++){
		if (searcharray(a[i].name,s)==1 || searcharray(a[i].com,s)==1){
			yaft[t]=i;
			t++;
		}
	}
	if (t==0) printf ("Hich kalaei baraye jostojuye shoma yaft nashod.\n");
	else{
		printf("\nListe kalahaye peyda shodeh:\n\n");
		for(i=0; t>i; i++) printfood(a,yaft[i]);
	}
}
void strcopy (char a[],char b[]){
	int i;
	for(i=0; b[i]!=0; i++) a[i]=b[i];
	a[i]=0;
}
void deletefood (struct food *a, struct food *b, int m){
	int choice,t,id,i,y=0,ib,anjam=0;
	for(t=0; a[t].id !=0 && m>t; t++);
	printf("ID Kalaei ke mikhahid hazf konid ra vared konid:\n");
	scanf("%d" ,& id);
	for(i=0; t>i && y==0; i++){
		if(a[i].id==id){
			y=1;
			i--;
		}
	}
	if (y==0) printf("Kalaei ba in ID peyda nashod.\n");
	else if (y==1){
		anjam=1;
		printf("\n1: Hazfe Daem\n2: Hazfe movaghat\n");
		printf("Enter your choice: ");
		scanf("%d" ,& choice);
		while(choice!=1 && choice!=2){
			printf("Na motabar.\n");
			printf("1: Hazfe Daem\n2: Hazfe movaghat\n");
			printf("Enter your choice: ");
			scanf("%d" ,& choice);
		}
		printf ("\nAya Motmaenid ke %s ba ID %d ra mikhahid hazf konid? (1:Bale || 2: Na)\n",a[i].name,a[i].id);
		scanf ("%d",& anjam);
		while(anjam!=1 && anjam!=2){
			printf("\nNa motabar.\n");
			printf ("Aya Motmaenid ke %s ba ID %d ra mikhahid hazf konid? (1:Bale || 2: Na)\n",a[i].name,a[i].id);
			scanf ("%d",& anjam);
		}
		if (choice==2 && anjam==1){
			for(ib=0; b[ib].id !=0 && 200>ib; ib++);
			if (ib==(200-1) && b[ib].id!=0){
				printf("Liste hazf shodeha kamelan por ast.\n");
				anjam=0;
			}
			if(anjam==1){
				b[ib].id=a[i].id;
				strcopy(b[ib].name,a[i].name);
				strcopy(b[ib].com,a[i].name);		
				b[ib].cost=a[i].cost;
				b[ib].date.y=a[i].date.y;
				b[ib].date.m=a[i].date.m;
				b[ib].date.d=a[i].date.d;
			}
		}
		if (anjam==1){
			a[i].id=a[t-1].id;
			strcopy(a[i].name,a[t-1].name);
			strcopy(a[i].com,a[t-1].name);		
			a[i].cost=a[t-1].cost;
			a[i].date.y=a[t-1].date.y;
			a[i].date.m=a[t-1].date.m;
			a[i].date.d=a[t-1].date.d;	
			a[t-1].id=0;
		}
	}
	if (anjam==1 && choice==1) printf("\nKalaye zekr shodeh hazfe daem shod.\n");
	if (anjam==1 && choice==2) printf("\nKalaye zekr shodeh movaghatan hazf shod.\n");
}
void reclyce (struct food *b,struct food *a,int m){
	int choice,i,id,y=0,t,anjam=1,ib,c2;
	printf("\n1: Show reclyce bin\n2: Recovery data\n3: Delete food(s) forever\n");
	printf("Enter your choice: ");
	scanf ("%d" ,& choice);
	while (choice<1 || choice>3){
		printf ("\nNa motabar\n");
		printf("1: Show reclyce bin\n2: Recovery data\n3: Delete food(s) forever\n");
		printf("Enter your choice: ");
		scanf ("%d" ,& choice);
	}
	if (choice==1){
		for (i=0; b[i].id!=0 && 200>i; i++){
			if(i==0) printf("\nListe kala haei ke ghabele bazyabi and.\n");
			printf ("\nKalaye %d: \n",i+1);
			printf ("ID: %d\n",b[i].id);
			printf ("Name: %s\n",b[i].name);
			printf ("Company: %s\n",b[i].com);
			printf ("Cost: %d\n",b[i].cost);
			printf ("Tarikhe Engheza: %d/%d/%d\n",b[i].date.y,b[i].date.m,b[i].date.d);
		}
		if(i==0) printf("\nHich kalaei baraye bazyabi vojud nadarad.\n");
	}
	if (choice==2){
		printf("\nID kalaei ra ke mikhahid bazyabi konid vared konid.\n");
		scanf("%d" ,& id);
		for(t=0; b[t].id!=0 && 200>t; t++);
		for(i=0; t>i && y==0; i++){
			if(b[i].id==id){
				y=1;
				i--;
			}
		}
		if(y==0) printf("\nKalaei ba in ID baraye bazyabi vojud nadarad.\n");
		else if(y==1){
			for(ib=0; a[ib].id !=0 && m>ib; ib++);
			if (ib==(m-1) && a[ib].id!=0){
				printf("Liste Kala haye shoma kamelan por ast.\n");
				anjam=0;
			}
			if (anjam==1){
				printf("Kalaye %s ba ID %d bazyabi khahad shod:\n",b[i].name,b[i].id);
				a[ib].id=b[i].id;
				strcopy(a[ib].name,b[i].name);
				strcopy(a[ib].com,b[i].name);		
				a[ib].cost=b[i].cost;
				a[ib].date.y=b[i].date.y;
				a[ib].date.m=b[i].date.m;
				a[ib].date.d=b[i].date.d;	
				
				b[i].id=b[t-1].id;
				strcopy(b[i].name,b[t-1].name);
				strcopy(b[i].com,b[t-1].name);		
				b[i].cost=b[t-1].cost;
				b[i].date.y=b[t-1].date.y;
				b[i].date.m=b[t-1].date.m;
				b[i].date.d=b[t-1].date.d;	
				b[t-1].id=0;
				printf("\nKalaye zekr shode bazyabi shod.\n");
			}
		}
	}
	if (choice==3){
		printf("\n1: Delete a food\n2: Delete all of foods\n");
		scanf("%d" ,& c2);
		if (c2==2){
			printf("\nAya motmaenid ke mikhahid hameye kalahaye darune satle zobale ra baraye hamishe hazf konid? (1:Bale || 2:na\n");
			scanf("%d",&anjam);
			while (anjam!=1 || anjam!=2){
				printf("\nNa motabar\n");
				printf("Aya motmaenid ke mikhahid hameye kalahaye darune satle zobale ra baraye hamishe hazf konid? (1:Bale || 2:na\n");
				scanf("%d",&anjam);
			}
			if(anjam==1){
				for(i=0; 200>i; i++) b[i].id=0;
				printf("Tamame kalahaye darune satle zobale	hazf shodand.\n");
			}
		}
		if(c2==1){
			printf("ID kalaei ra ke mikhahid az satle zobale hazf konid ra vared konid.\n");
			scanf("%d" ,& id);
			for(t=0; b[t].id!=0 && 200>t; t++);		
			for(i=0; t>i && y==0; i++){
				if(b[i].id==id){
					y=1;
					i--;
				}	
			}
			if(y==0) printf("\nKalaei ba in ID baraye hazf vojud nadarad.\n");
			else if(y==1){
				printf("Kalaye %s ba ID %d baraye hamishe hazf khahad shod:\n",b[i].name,b[i].id);
				b[i].id=b[t-1].id;
				strcopy(b[i].name,b[t-1].name);
				strcopy(b[i].com,b[t-1].name);		
				b[i].cost=b[t-1].cost;
				b[i].date.y=b[t-1].date.y;
				b[i].date.m=b[t-1].date.m;
				b[i].date.d=b[t-1].date.d;	
				b[t-1].id=0;
				printf("\nKalaye zekr shode az satle zobale hazf shod.\n");
			}
		}
	}		
}
int randid(struct food *a,struct food *b,int m){
	int rnd,check=0,i;
	while(check==0){
		check=1;
		rnd=rand()%9000+1000;
		for(i=0; a[i].id!=0 && m>i; i++){
			if(a[i].id==rnd) check=0;
		}	
		for(i=0; b[i].id!=0 && 200>i; i++){
			if(b[i].id==rnd) check=0;
		}
	}
	return rnd;
}				
void upfood (struct food *a,int m){
	int id,i,y=0;
	printf("\nID kalaei ra ke mikhahid beruz konid ra vared konid:\n");
	scanf("%d" ,& id);
	for(i=0; a[i].id!=0 && m>i && y==0; i++){
		if(a[i].id==id){
			y=1;
			i--;
			printf("peyda\n");
		}
	}
	if(y==0) printf("\nKalaei ba in ID yaft nashod.\n");
	else{
		printf("\nName kala :\n");
		scanf("%s",a[i].name);
		printf("Name sherkat sazande :\n");
		scanf("%s",a[i].com);
		printf("Gheymate kala :\n");
		scanf("%d",&a[i].cost);
		printf("Be tartib sal/mah/rooz tarikh engheza :\n");
		scanf("%d%d%d",&a[i].date.y,&a[i].date.m,&a[i].date.d);
	}
	printf("\nKalaye morede nazar beruz shod.\n");
}
void showsort(struct food *a,int m){
	const int MAX=m;
	int t,i,big=-1,h,yaft[MAX],j,choice;
	for(i=0; m>i; i++) a[i].sort=m+1;
	for(t=0; a[t].id!=0 && m>t; t++);
	for(i=0; t>i; i++){
		big=-1;
		for(j=0; t>j; j++){
			if(a[j].cost>big && a[j].sort>i){
				big=a[j].cost;
				h=j;
			}
		}
		a[h].sort=i;
		yaft[i]=h;
	}
	printf("\nKala ha bar hasbe gheymat be surate soudi moratab shavand ya nozuli?\n");		
	printf("1: Soudi\n2: Nozuli\n");
	scanf("%d" ,& choice);
	while(choice!=1 && choice!=2){
		printf("Na motabar\n");
		printf("1: Soudi\n2: Nozuli\n");
		scanf("%d" ,& choice);
	}
	if (choice==2){
		for(i=0; t>i; i++){
			printf("\nKalaye %d:\n",i+1);
			printfood(a,yaft[i]);
		}
	}
	if (choice==1){
		for(i=0; t>i; i++){
			printf("\nKalaye %d:\n",i+1);
			printfood(a,yaft[t-1-i]);
		}
	}		
}
