#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct signal_element{
	char bit_stream[3];
	float start,end;
	};
struct signal_element *element;
int index_of_element = 0;
int amplitude = 1;
int carrier_frequency = 100;
int make_qpsk(){
	FILE *fp = fopen("output.txt", "w");
	int i;
	float data_rate,length,j,k;
	printf("length of digital signal...  ");
	scanf("%f",&length);
	
	char *signal = (char*)malloc(length*sizeof(length));
	printf("digital signal...  ");
	scanf("%s",signal);
	
	printf("Data rate..  ");
	scanf("%f",&data_rate);
	
	//printf("Time interval...  ");
	//float interval;
	//scanf("%f",&interval);
	
	float time_length = length/data_rate;
	
	element = (struct signal_element*)malloc(length*sizeof(struct signal_element));
	float time = 0;
	for(i = 0;i<strlen(signal);i = i+2){
		char bit_stream[3];
		bit_stream[0] = signal[i];
		bit_stream[1] = signal[i+1];
		bit_stream[2] = '\0';
		strcpy(element[index_of_element].bit_stream,bit_stream);
		element[index_of_element].start = time;
		element[index_of_element].end = time+2*(1/data_rate);
		index_of_element++;
		time = time+2*(1/data_rate);
		
	}
	/*for(i = 0;i<index_of_element;i++){
		printf("%s %f %f\n",element[i].bit_stream,element[i].start,element[i].end);
	}*/
	for(i=0;i<index_of_element;i++){
		if(strcmp(element[i].bit_stream,"11")==0){
			float step = (element[i].end-element[i].start)/100.0f;
			for( j = element[i].start ; j<element[i].end; j = j+step){
			float ans = amplitude*cos( ((6.28*carrier_frequency*j)/360) +0.785);
			fprintf(fp,"%f %f\n", j, ans);
			//printf("%f %f\n",j,ans);
			}

		}
		else if(strcmp(element[i].bit_stream,"01")==0){
		float step = (element[i].end-element[i].start)/100.0f;
			for( j = element[i].start ; j<element[i].end; j = j+step){
			float ans = amplitude*cos( ((6.28*carrier_frequency*j)/360)+2.355);
			fprintf(fp,"%f %f\n", j, ans);
		//	printf("%f %f\n",j,ans);
			}	
		}
		else if(strcmp(element[i].bit_stream,"00")==0){
		float step = (element[i].end-element[i].start)/100.0f;
			for( j = element[i].start ; j<element[i].end; j = j+step){
			float ans = amplitude*cos( ((6.28*carrier_frequency*j)/360)-2.355 );
			fprintf(fp,"%f %f\n", j, ans);
			//printf("%f %f\n",j,ans);
			}

		}
		else if(strcmp(element[i].bit_stream,"10")==0){
			float step = (element[i].end-element[i].start)/100.0f;
			for( j = element[i].start ; j<element[i].end; j = j+step){
			float ans = amplitude*cos( ((6.28*carrier_frequency*j)/360)-0.785);
			fprintf(fp,"%f %f\n", j, ans);
		//	printf("%f %f\n",j,ans);
			}
		}
	}
return 0;
}
int main()
{
make_qpsk();
return 0;
}

