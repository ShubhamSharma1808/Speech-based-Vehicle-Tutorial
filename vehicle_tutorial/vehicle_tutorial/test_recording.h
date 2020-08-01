
// This file test the live recording of digits


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<float.h>



long double test_input1();
void load_file();
void load_model(int,int);
void read_codebook();
long double abs1(long double);
void compute_max_sample(char*);
long double compute_energy(int);
void dcShift();
void normalize();
void compute_ri();
void compute_ai();
void compute_ci();
void compute_raised_ci();
void compute_observation_symbol();

void alpha_computation1();
int test(int);

long double a1[6][6];			//global variable declaration and initialization
long double b1[6][33];
int o1[150];
int index=0;
int start_frame,end_frame;
long double pie1[6];
long double alpha1[150][6];


long double max_sample;
long double sample1[320];

char modelfilename1[50];
char modelfilename11[50];

long double ri1[15];
long double ai1[15][15];
long double ci1[15];
long double k1[15];
long double e1[15];
long double codebook1[33][13];
int n=5,m=32,T;
long double avg_energy;
long double energy[500];
long double avg_sample;
long double prob;
long double wt1[]={1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0};
long double DC_SHIFT1= -1.154939;
long double sine_window1[]={1.000000000,2.552914271,4.000000000,5.242640687,6.196152423,6.795554958,7.000000000,6.795554958,6.196152423,5.242640687,4.000000000,2.552914271,1.000000000};


int recording_test()
{
	char ch='n';
	int i=0,k=0,result=0;
	long double x=0,accuracy=0,avg=0;
	read_codebook();
	printf("*******recording digit *****************");
	
		system("Recording_Module.exe 2 input_file.wav input_file.txt");				//recording module call


		load_file();
		prob=0;
		x=0;
		/*strcpy(modelfilename11,"model\\iteration_3\\194101020_");
		result=test(3);
		if(prob<0.01)
		{	
			strcpy(modelfilename11,"model\\iteration_2\\jp_");
			result=test(2);
			
		}
		if(prob<0.01)
		{	*/
			strcpy(modelfilename11,"models\\iteration_1\\jp_");
			result=test(1);
			
		//}
		accuracy++;
		if(prob==0.0)
			printf("\nsorry not able to recognize try again !\n");
		else
			printf("\ndigit is recognized as : %d \n",result);

return result;

}

int test(int it)
{
	int result=0;
	long double x=0;
	for(int j=0;j<=11;j++)
		{
			load_model(it,j);
			
			x=test_input1();
			if(x>prob)
			{
				prob=x;
				result=j;
			}

		}

	return result;
}


void load_model(int it,int digit)			//This function is used to load the trained model to test input on it.
{
	int i=1,j=1;

	strcpy(modelfilename1,modelfilename11);
	itoa(digit,modelfilename1+strlen(modelfilename1),10);
	strcat(modelfilename1,"_it_");
	itoa(it,modelfilename1+strlen(modelfilename1),10);
	strcat(modelfilename1,".txt");
	

	FILE *fp=fopen(modelfilename1,"r");			//file opening
	

	if(fp==NULL)
	{
		printf("problem in opening file %s", modelfilename1);
		exit(0);
	}

	for(i=1;i<=n;i++)
	{	pie1[i]=0;
		fscanf(fp,"%Lf",&pie1[i]);
	}
		
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{		
			a1[i][j]=0;
			fscanf(fp,"%Le",&a1[i][j]);
		}
	}
	
	
	for(i=1;i<=n;i++)
	{	for(j=1;j<=m;j++)
		{
			b1[i][j]=0;
			fscanf(fp,"%Le",&b1[i][j]);
		}
	}

//	printf("digit %d model loaded.... \n",digit);

	fclose(fp);
}


void load_file()			//This function used to load recording file for testing
{

	int count=0,i=0,overlap=240,flag=0,f=0,f1=0;
	long double energy=0,energy1=0,energy2=0,energy3=0;
	bool start=false,end=false;


	
	avg_energy=0;
	avg_sample=0;
	compute_max_sample("input_file.txt");		


	FILE *fp_input=fopen("input_file.txt","r");		//file opening
	
	index=0;
	if(fp_input==NULL)
	{
		printf("problem in opening file input_file.txt");
		exit(0);
	}

	while(true)
	{
		if(count==0)
		{
		   for(i=0;i<320;i++)
		   {
				fscanf(fp_input,"%lf",&sample1[i]);
				if(feof(fp_input))
				{	
					flag=1;
					break;
				}
		   }
		}
		else
		{
			for(i=0;i<320;i++)
		   {
			   if(i<overlap)
					sample1[i]=sample1[i+320-overlap];
			   else
			   {
					fscanf(fp_input,"%lf",&sample1[i]);
					if(feof(fp_input))
					{	
						flag=1;
						break;
					}
				}
		   }
		}
	   if(flag==1)
		   break;
	   count++;
	   
	   dcShift();
	   normalize();
	/*	energy=energy1;
	   energy1=compute_energy(100);
		if(count>=2)
		{
			if(energy1>=3*energy&&!start)
			{
				start=true;
				printf("\nstart frame  %d ",f1);
			}
			if(!start)
				continue;
			
			if(3*energy1<=energy&&!end)
			{
				end=true;
				printf("\nending frame  %d ",f1);
			}
		}
		
		if(start&&!end)
		{*/
	 //  if(f1>=100&&f1<=200)
	    if(f1>=start_frame&&f1<=end_frame)
		{
			compute_ri();
			compute_ai();
			compute_ci();
			compute_raised_ci();
			
				compute_observation_symbol();
			
			f++;
	   }
			
		//}
		f1++;
	
	}
	//printf("\n total frames    %d  steady frame %d\n ",f1,f);
	if(index>150)
		T=149;
	else
		T=index;
	fclose(fp_input);
	
}



void read_codebook()  //This function is used to read codebook from file
{
	FILE *fp_c=fopen("jp.txt","r");

	if(fp_c==NULL)
	{
		printf("problem in opening file codebook.txt");
		exit(0);
	}

	for(int i=1;i<=32;i++)
	{
		for(int j=1;j<=12;j++)
		{
			fscanf(fp_c,"%Lf",&codebook1[i][j]);
		}
	}

	fclose(fp_c);

}




long double abs1(long double t)
{
	if(t<0)
		return -t;
	else
		return t;
}


void compute_max_sample(char filename[50])			//This function compute the maximum sample for normalization
{
	int count=0,f=0,max_index=0;
	long double x=0,max=0,sum=0,sum1=0,max_energy=0;
	FILE *fp1=fopen(filename,"r");

	FILE *fp2=fopen("input_file01.txt","w");
	if(fp1==NULL||fp2==NULL)
	{
		printf("problem in opening file %s",filename);
		exit(0);
	}
	
	while(true)
	{
		
		fscanf(fp1,"%Lf",&x);
		sample1[count++]=x;
		//sum1+=x;
		x=abs1(x);
		
		if(feof(fp1))
			break;
		if(max<x)
		{	
			max=x;
			max_index=count;
		}
		
		
		if(count==80)
		{	
			x=compute_energy(80);
			energy[f++]=x;
			sum+=x;
			count=0;
		}
		
		
	}
	max_sample=max;
	avg_energy=sum/f;

	
	for(int i=25;i<f;i++)
	{
		if(energy[i]>=1.8*avg_energy)
		{
			start_frame=i-1;
			break;
		}
	}
	if(start_frame<=0)
		start_frame=1;
	else
		start_frame=start_frame-10;

	
	for(int i=f-1;i>0;i--)
	{
		if(energy[i]>=0.05*avg_energy)
		{
			end_frame=i-1;
			break;
		}
	}
	if(end_frame==0)
		end_frame=f-1;
	else
		end_frame=end_frame+20;

	if(end_frame>f)
		end_frame=f-10;
	printf("\nstart %d,end %d  total frame %d \n",start_frame,end_frame,end_frame-start_frame);
	int f1=0;
	rewind(fp1);
	while(true)
	{
		
		fscanf(fp1,"%d",&x);
		if(feof(fp1))
			break;
		f1++;
		 if(f1>=start_frame*80&&f1<=end_frame*80)
		{
			
				fprintf(fp2,"%d\n",x);
		}
		
		
		
		
	}



	fclose(fp2);
	
	fclose(fp1);
}





long double test_input1()
{
	int k=0;
	long double sum=0;
		
		alpha_computation1();
	/*	beta_computation();
		gamma_computation();
		delta_computation();
		xi_computation();
		update_model();
		if(k==20)
			break;*/
	
	for(int i=1;i<=n;i++)
		sum+=alpha1[T][i];

	return sum;

}


void alpha_computation1()			//This function is used to compute parameter alpha
{

	int i=1,j=1,t=1;
	long double sum=0;


	for(i=1;i<=n;i++)					//Initializing alpha at t=1
	{
		alpha1[1][i]=pie1[i]*b1[i][o1[1]];
	}


	for(t=1;t<T;t++)					//Induction step
	{
		for(j=1;j<=n;j++)
		{
			for(i=1;i<=n;i++)
			{
				sum+=alpha1[t][i]*a1[i][j];
			}
			alpha1[t+1][j]=sum*b1[j][o1[t+1]];
			sum=0;
		}
	}

	
}


long double compute_energy(int x)		//This function is used to compute energy of a frame
{
	long double sum=0;

	for(int i=0;i<x;i++)
	{
		sum+=sample1[i]*sample1[i];
	}
	return sum/x;

}

void dcShift()
{					
	int i=0;							//local variable declaration and initiallization
	
	for(i=0;i<320;i++)
	{
		sample1[i]=sample1[i]-DC_SHIFT1;
	}
}


										
void normalize()		// This function is used to compute normalized values for each frame.
{
	
	int i=0;					

	for(i=0;i<320;i++)
	{
		sample1[i]=(sample1[i]*5000)/max_sample;
	}
}


void compute_ri()				//This function compute the ri's for input frame
{
	long double sum=0;
	
	for(int i=0;i<=12;i++)
	{
	
		for(int m=0;m<(320-i);m++)
		{
		sum+=sample1[m]*sample1[m+i];
		}
		ri1[i]=sum;
	
		sum=0;
	
	}
}

void compute_ai()			//This function computes ai's for input frame
{
	int i=0,j=0;
	int p=12;
	long double sum=0;

	e1[0]=ri1[0];
	for(i=1;i<=p;i++){
		for(j=1;j<=i-1;j++){
			sum+=ai1[i-1][j]*ri1[abs(i-j)];
		}
		k1[i]=(ri1[i]-sum)/e1[i-1];
		ai1[i][i]=k1[i];
		for(j=1;j<i;j++){
			ai1[i][j]=ai1[i-1][j]-(k1[i]*ai1[i-1][i-j]);
		}
		e1[i]=(1-(k1[i]*k1[i]))*e1[i-1];
	sum=0;
	}
	
}



void compute_ci()				//This function compute ci's for input frame
{	
	int p=12;
	long double x=0,sum=0,y=0;
	
	for(int m=1;m<=p;m++)
	{
		for(int k=1;k<=(m-1);k++)
		{
			x=m;
			y=k;
			sum+=(y/x)*ci1[k]*ai1[p][m-k];
		}

		ci1[m]=ai1[p][m]+sum;
	
	sum=0.0;
	}

}


void compute_raised_ci()				//this function is used to apply RAISED SINE WINDOW on ci's.
{	
	int i=0;
			
	for(i=1;i<=12;i++)
	{
		ci1[i]=ci1[i]*sine_window1[i-1];
	}						

}


void compute_observation_symbol()			//This function used to compute observation sequence for a input speech signal
{
	int minindex=0;
	long double sum=0,min=FLT_MAX;
	
	for(int i=1;i<=32;i++)
	{
		for(int j=1;j<=12;j++)
		{
			sum+=wt1[j-1]*(ci1[j]-codebook1[i][j])*(ci1[j]-codebook1[i][j]);
		}

		if(min>sum)
		{
			min=sum;
			minindex=i;
		}
		sum=0;
	}

	o1[++index]=minindex;
//	printf("\n state =%d",minindex);
	
	

}
