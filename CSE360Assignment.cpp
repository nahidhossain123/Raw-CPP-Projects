#include<iostream>
using namespace std;

int Matrix[100][100],row,coloumn,Sequence[50],LoadSeq[100],LoadPos[100],pos=0,pos1=0;

int HIT_MISS(int seq,int modu_val)
{
   	int Is_HIT=0;
   	for(int i=0;i<coloumn;i++)
   	{
   		if(Matrix[modu_val][i]==seq)
   		{
   		  Is_HIT=1;
		  break;	
		}
		else
		{
			Is_HIT=0;
		}
	}
	return Is_HIT;
}



void Cache_Empty_Check(int seq,int modu_val)
{
	pos1=0;
	int isempty=0;
  	for(int i=0;i<coloumn;i++)
  	{
  	 	if(Matrix[modu_val][i]==-2)
  	 	{
  	 	 	Matrix[modu_val][i]=seq;
			LoadSeq[pos]=seq;
			pos++;
			isempty=1;
			break;		
		}
        else
        {
        	isempty=0;
		}
	}
	
	if(!isempty)
	{
		int matchcount=0;
		for(int j=pos-1;j>0;j--)
		{
			for(int i=0;i<coloumn;i++)
			{
				if(Matrix[modu_val][i]==LoadSeq[j] && matchcount!=coloumn)
				{
					LoadPos[pos1]=j;
					pos1++;
					matchcount++;
				}	
			}
		}
		int min=LoadPos[0];
		for(int i=0;i<pos1;i++)
		{
			if(min>LoadPos[i])
			{
				min=LoadPos[i];
			}
		}
		
		for(int i=0;i<coloumn;i++)
		{
			if(Matrix[modu_val][i]==LoadSeq[min])
			{
				Matrix[modu_val][i]=seq;
				LoadSeq[pos]=seq;
				pos++;
			}
		}	
		
	}
	
	
}


int main()
{
	int n,m,i=0,modulus_val;
	cin>>n>>m;
	while(Sequence[i-1]!=-1)
	{
		cin>>Sequence[i];  
		i++;
	}
	coloumn=n;
	row=m/n;
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<coloumn;j++)
		{
			Matrix[i][j]=-2;
		}
	}
	
	i=0;
	while(Sequence[i]!=-1)
	{
		modulus_val=Sequence[i]%row;
		if(HIT_MISS(Sequence[i],modulus_val)==1)
		{
			LoadSeq[pos]=Sequence[i];
			pos++;
			cout<<"HIT"<<endl;
		 	for(int i=0;i<row;i++)
			{
			 	for(int j=0;j<coloumn;j++)
			 	{
			 		if(Matrix[i][j]==-2)
			 		{
			 			cout<<"B"<<"  ";
					}
					else
					{
						cout<<Matrix[i][j]<<"  ";	
					}	
				}
				cout<<endl;
			}	
		}
		else
		{
			Cache_Empty_Check(Sequence[i],modulus_val);
			cout<<"MISS"<<endl;
		 	for(int i=0;i<row;i++)
			{
			 	for(int j=0;j<coloumn;j++)
			 	{
			 		if(Matrix[i][j]==-2)
			 		{
			 			cout<<"B"<<"  ";
					}
					else
					{
						cout<<Matrix[i][j]<<"  ";	
					}
				}
				cout<<endl;
			}		
		} 
		i++; 
	}
	
}
