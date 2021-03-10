#include<iostream>
#include<fstream>
#include <string>
#include<graphics.h>

using namespace std;

int NoOfVertices=0,count=0,Points[50],GraphicsXY[10],StartCoordinate[50],Vertexcount=0,StartVertex=0;

float OldCoordinate[100],XYValue[10],NewCoordinate[100];
string ClipingOrder[10];


void CartesianToGraphics()
{
	for(int i=0;i<2*NoOfVertices;i=i+2)
	{
		if(OldCoordinate[i]<0&&OldCoordinate[i+1]>0) //condition -+
		{
			Points[i]=400+int(OldCoordinate[i]);
			Points[i+1]=400-int(OldCoordinate[i+1]);
		}
		else if(OldCoordinate[i]<0&&OldCoordinate[i+1]<0)//condition --
		{
			Points[i]=400+int(OldCoordinate[i]);
			Points[i+1]=400-int(OldCoordinate[i+1]);	
		}
		else if(OldCoordinate[i]>0&&OldCoordinate[i+1]>0)//condition ++
		{
			Points[i]=400+int(OldCoordinate[i]);
			Points[i+1]=400-int(OldCoordinate[i+1]);
		}
		else if(OldCoordinate[i]>0&&OldCoordinate[i+1]<0)//condition +-
		{
			Points[i]=400+int(OldCoordinate[i]);
			Points[i+1]=400-int(OldCoordinate[i+1]);
		}
		if(i==2*NoOfVertices-2)
		{
			
			Points[i+2]=Points[0];
			Points[i+3]=Points[1];
		}
	}
	Vertexcount=(2*NoOfVertices)+2;
}

void XYConversion()
{
	
	for(int i=0;i<2;i++)
	{
		if(XYValue[i]>0)
		{
			GraphicsXY[i]=400+int(XYValue[i]);
		}
		else
		{
			GraphicsXY[i]=400+int(XYValue[i]);
		}
	}
	for(int i=2;i<4;i++)
	{
		if(XYValue[i]>0)
		{
			GraphicsXY[i]=400-int(XYValue[i]);
		}
		else
		{
			GraphicsXY[i]=400-int(XYValue[i]);
		}
	}
}

void DrawGraph(string str)
{
	if(str=="L")
	{
		int win1;
		win1=initwindow(800,800,"win1");
		setcurrentwindow(win1);
		line(GraphicsXY[0],0,GraphicsXY[0],800);
		line(GraphicsXY[1],0,GraphicsXY[1],800);
		line(0,GraphicsXY[2],800,GraphicsXY[2]);
		line(0,GraphicsXY[3],800,GraphicsXY[3]);
		drawpoly(StartVertex/2,StartCoordinate);
		
		drawpoly(Vertexcount/2,Points);
		setfillstyle(SOLID_FILL,BLUE);
		fillpoly(Vertexcount/2,Points);
			
	}
	else if(str=="R")
	{
		int win2;
		win2=initwindow(800,800,"win2");
		setcurrentwindow(win2);
		line(GraphicsXY[0],0,GraphicsXY[0],800);
		line(GraphicsXY[1],0,GraphicsXY[1],800);
		line(0,GraphicsXY[2],800,GraphicsXY[2]);
		line(0,GraphicsXY[3],800,GraphicsXY[3]);
		drawpoly(StartVertex/2,StartCoordinate);
		setfillstyle(SOLID_FILL,BLUE);
		drawpoly(Vertexcount/2,Points);
		fillpoly(Vertexcount/2,Points);
		
	}
	
	else if(str=="T")
	{
		int win2;
		win2=initwindow(800,800,"win2");
		setcurrentwindow(win2);
		line(GraphicsXY[0],0,GraphicsXY[0],800);
		line(GraphicsXY[1],0,GraphicsXY[1],800);
		line(0,GraphicsXY[2],800,GraphicsXY[2]);
		line(0,GraphicsXY[3],800,GraphicsXY[3]);
		drawpoly(StartVertex/2,StartCoordinate);
		setfillstyle(SOLID_FILL,BLUE);
		drawpoly(Vertexcount/2,Points);
		fillpoly(Vertexcount/2,Points);
		
	}
	else if(str=="B")
	{
		int win2;
		win2=initwindow(800,800,"win2");
		setcurrentwindow(win2);
		line(GraphicsXY[0],0,GraphicsXY[0],800);
		line(GraphicsXY[1],0,GraphicsXY[1],800);
		line(0,GraphicsXY[2],800,GraphicsXY[2]);
		line(0,GraphicsXY[3],800,GraphicsXY[3]);
		drawpoly(StartVertex/2,StartCoordinate);
		setfillstyle(SOLID_FILL,BLUE);
		drawpoly(Vertexcount/2,Points);
		fillpoly(Vertexcount/2,Points);
		
	}
	getch();
}

void Left()
{
	int pos=0;
	cout<<"Cliping With Respect To The Left Edge....."<<endl;
	for(int i=0;i<2*NoOfVertices;i++)
	{
		NewCoordinate[i]=OldCoordinate[i];
	}

	for(int i=0;i<=2*NoOfVertices;i=i+2)
	{
		if((XYValue[0]>NewCoordinate[i]&&XYValue[0]<=NewCoordinate[i+2])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //Out-In Condition
		{
			OldCoordinate[pos]=XYValue[0];
			OldCoordinate[pos+1]=(((XYValue[0]-NewCoordinate[i])*(NewCoordinate[i+3]-NewCoordinate[i+1]))/(NewCoordinate[i+2]-NewCoordinate[i]))+NewCoordinate[i+1];//formula (x-x1/x2-x1=y-y1/y2-y1) Find the intersecting point between two line   
		   // OldCoordinate[pos+2]=NewCoordinate[i+2];
			//OldCoordinate[pos+3]=NewCoordinate[i+3];
			pos+=4;		
		}
		else if((XYValue[0]<NewCoordinate[i]&&XYValue[0]>NewCoordinate[i+2])&&i!=2*NoOfVertices && i!=2*NoOfVertices-2) //In-Out Condition
		{
			OldCoordinate[pos]=XYValue[0];
			OldCoordinate[pos+1]=(((XYValue[0]-NewCoordinate[i])*(NewCoordinate[i+3]-NewCoordinate[i+1]))/(NewCoordinate[i+2]-NewCoordinate[i]))+NewCoordinate[i+1];   
			pos+=2;
		}
		else if((XYValue[0]<=NewCoordinate[i]&&XYValue[0]<=NewCoordinate[i+2])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //In-In Condition
		{
			OldCoordinate[pos]=NewCoordinate[i+2];
			OldCoordinate[pos+1]=NewCoordinate[i+3];  
			pos+=2;
		}
	    if(i==2*NoOfVertices) //Last To First Itaration
		{
			if((XYValue[0]<=NewCoordinate[0]&&XYValue[0]>NewCoordinate[i-2]))//out-in condition
			{
				OldCoordinate[pos]=XYValue[0];
				OldCoordinate[pos+1]=(((XYValue[0]-NewCoordinate[0])*(NewCoordinate[i-1]-NewCoordinate[1]))/(NewCoordinate[i-2]-NewCoordinate[0]))+NewCoordinate[1];
				OldCoordinate[pos+2]=NewCoordinate[0];
				OldCoordinate[pos+3]=NewCoordinate[1];
				pos+=4;		
			}
			else if((XYValue[0]>NewCoordinate[0]&&XYValue[0]<NewCoordinate[i-2]))//In-out condition
			{
				OldCoordinate[pos]=XYValue[0];
				OldCoordinate[pos+1]=(((XYValue[0]-NewCoordinate[0])*(NewCoordinate[i-1]-NewCoordinate[1]))/(NewCoordinate[i-2]-NewCoordinate[0]))+NewCoordinate[1];   
				pos+=2;
			}
			else if((XYValue[0]<=NewCoordinate[0]&&XYValue[0]<=NewCoordinate[i-2]))//In-In Condition
			{	
				OldCoordinate[pos]=NewCoordinate[0];
				OldCoordinate[pos+1]=NewCoordinate[1];	
				pos+=2;
			}
		}
		count++;
	}
	cout<<"New Sequence:";
	for(int j=0;j<pos;j=j+2)
	{
		cout<<"("<<OldCoordinate[j]<<","<<OldCoordinate[j+1]<<")";
		Points[j]=int(OldCoordinate[j]);
		Points[j+1]=int(OldCoordinate[j+1]);
		if(j+2==pos)
		{	
			Points[j+2]=int(OldCoordinate[0]);
			Points[j+3]=int(OldCoordinate[1]);
		}
	}
	NoOfVertices=pos/2;
	CartesianToGraphics();
	DrawGraph("L");
	cout<<endl<<endl;
}

void Right()
{
	int pos=0;
	cout<<"Cliping With Respect To The Right Edge....."<<endl;
	for(int i=0;i<2*NoOfVertices;i++)
	{
		NewCoordinate[i]=OldCoordinate[i];
	}

	for(int i=0;i<=2*NoOfVertices;i=i+2)
	{
		if((XYValue[1]<=NewCoordinate[i]&&XYValue[1]>=NewCoordinate[i+2])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //Out-In Condition
		{
			OldCoordinate[pos]=XYValue[1];
			OldCoordinate[pos+1]=(((XYValue[1]-NewCoordinate[i])*(NewCoordinate[i+3]-NewCoordinate[i+1]))/(NewCoordinate[i+2]-NewCoordinate[i]))+NewCoordinate[i+1];   
			OldCoordinate[pos+2]=NewCoordinate[i+2];
			OldCoordinate[pos+3]=NewCoordinate[i+3];
			pos+=4;			
		}
		else if((XYValue[1]>NewCoordinate[i]&&XYValue[1]<NewCoordinate[i+2])&&i!=2*NoOfVertices && i!=2*NoOfVertices-2) //In-Out Condition
		{
			OldCoordinate[pos]=XYValue[1];
			OldCoordinate[pos+1]=(((XYValue[1]-NewCoordinate[i])*(NewCoordinate[i+3]-NewCoordinate[i+1]))/(NewCoordinate[i+2]-NewCoordinate[i]))+NewCoordinate[i+1];   
			pos+=2;
		}
		else if((XYValue[1]>=NewCoordinate[i]&&XYValue[1]>=NewCoordinate[i+2])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //In-In Condition
		{
			OldCoordinate[pos]=NewCoordinate[i+2];
			OldCoordinate[pos+1]=NewCoordinate[i+3];  
			pos+=2;
		}
	    if(i==2*NoOfVertices) //Last To First Itaration
		{
			if((XYValue[1]>=NewCoordinate[0]&&XYValue[1]<NewCoordinate[i-2]))//out-in condition
			{
				OldCoordinate[pos]=XYValue[1];
				OldCoordinate[pos+1]=(((XYValue[1]-NewCoordinate[0])*(NewCoordinate[i-1]-NewCoordinate[1]))/(NewCoordinate[i-2]-NewCoordinate[0]))+NewCoordinate[1];
				OldCoordinate[pos+2]=NewCoordinate[0];
				OldCoordinate[pos+3]=NewCoordinate[1];
				pos+=4;
					
			}
			else if((XYValue[1]<NewCoordinate[0]&&XYValue[1]>NewCoordinate[i-2]))//In-out condition
			{
				OldCoordinate[pos]=XYValue[1];
				OldCoordinate[pos+1]=(((XYValue[1]-NewCoordinate[0])*(NewCoordinate[i-1]-NewCoordinate[1]))/(NewCoordinate[i-2]-NewCoordinate[0]))+NewCoordinate[1];   
				pos+=2;
			}
			else if((XYValue[1]>=NewCoordinate[0]&&XYValue[1]>=NewCoordinate[i-2]))//In-In Condition
			{	
				OldCoordinate[pos]=NewCoordinate[0];
				OldCoordinate[pos+1]=NewCoordinate[1];	
				pos+=2;
			}
		}
		count++;
	}
	cout<<"New Sequence:";
	for(int j=0;j<pos;j=j+2)
	{
		cout<<"("<<OldCoordinate[j]<<","<<OldCoordinate[j+1]<<")";
		Points[j]=int(OldCoordinate[j]);
		Points[j+1]=int(OldCoordinate[j+1]);
		if(j+2==pos)
		{	
			Points[j+2]=int(OldCoordinate[0]);
			Points[j+3]=int(OldCoordinate[1]);
		}
	}	
	NoOfVertices=pos/2;
	CartesianToGraphics();
	DrawGraph("R");
	cout<<endl<<endl;

}

void Top()
{
	int pos=0;
	cout<<"Cliping With Respect To The Top Edge....."<<endl;
	for(int i=0;i<2*NoOfVertices;i++)
	{
		NewCoordinate[i]=OldCoordinate[i];
	}

	for(int i=0;i<=2*NoOfVertices;i=i+2)
	{
		if((XYValue[3]<NewCoordinate[i+1]&&XYValue[3]>=NewCoordinate[i+3])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //Out-In Condition
		{
			OldCoordinate[pos]=(((XYValue[3]-NewCoordinate[i+1])*(NewCoordinate[i+2]-NewCoordinate[i]))/(NewCoordinate[i+3]-NewCoordinate[i+1]))+NewCoordinate[i];
			OldCoordinate[pos+1]=XYValue[3]; 
			OldCoordinate[pos+2]=NewCoordinate[i+2];
			OldCoordinate[pos+3]=NewCoordinate[i+3];
			pos+=4;
				
		}
		else if((XYValue[3]>NewCoordinate[i+1]&&XYValue[3]<NewCoordinate[i+3])&&i!=2*NoOfVertices && i!=2*NoOfVertices-2) //In-Out Condition
		{
			OldCoordinate[pos]=(((XYValue[3]-NewCoordinate[i+1])*(NewCoordinate[i+2]-NewCoordinate[i]))/(NewCoordinate[i+3]-NewCoordinate[i+1]))+NewCoordinate[i];   
			OldCoordinate[pos+1]=XYValue[3];
			pos+=2;
		}
		else if((XYValue[3]>=NewCoordinate[i+1]&&XYValue[3]>=NewCoordinate[i+3])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //In-In Condition
		{
			OldCoordinate[pos]=NewCoordinate[i+2];
			OldCoordinate[pos+1]=NewCoordinate[i+3];  
			pos+=2;
		}
	    if(i==2*NoOfVertices) //Last To First Itaration
		{
			if((XYValue[3]>=NewCoordinate[1]&&XYValue[3]<NewCoordinate[i-1]))//out-in condition
			{
				OldCoordinate[pos]=(((XYValue[3]-NewCoordinate[1])*(NewCoordinate[i-2]-NewCoordinate[0]))/(NewCoordinate[i-1]-NewCoordinate[1]))+NewCoordinate[0];
				OldCoordinate[pos+1]=XYValue[3];
				OldCoordinate[pos+2]=NewCoordinate[0];
				OldCoordinate[pos+3]=NewCoordinate[1];
				pos+=4;
					
			}
			else if((XYValue[3]<NewCoordinate[1]&&XYValue[3]>NewCoordinate[i-1]))//In-out condition
			{
				OldCoordinate[pos]=(((XYValue[3]-NewCoordinate[1])*(NewCoordinate[i-2]-NewCoordinate[0]))/(NewCoordinate[i-1]-NewCoordinate[1]))+NewCoordinate[0];
				OldCoordinate[pos+1]=XYValue[3];   
				pos+=2;
			}
			else if((XYValue[3]>=NewCoordinate[1]&&XYValue[3]>=NewCoordinate[i-1]))//In-In Condition
			{	
				OldCoordinate[pos]=NewCoordinate[0];
				OldCoordinate[pos+1]=NewCoordinate[1];	
				pos+=2;
			}
		}
		count++;
	}
	cout<<"New Sequence:";
	for(int j=0;j<pos;j=j+2)
	{
		cout<<"("<<OldCoordinate[j]<<","<<OldCoordinate[j+1]<<")";
		Points[j]=int(OldCoordinate[j]);
		Points[j+1]=int(OldCoordinate[j+1]);
		if(j+2==pos)
		{	
			Points[j+2]=int(OldCoordinate[0]);
			Points[j+3]=int(OldCoordinate[1]);
		}
	}
	NoOfVertices=pos/2;	
	CartesianToGraphics();
	DrawGraph("L");
	cout<<endl<<endl;
	
}

void Bottom()
{
	int pos=0;
	cout<<"Cliping With Respect To The Bottom Edge....."<<endl;
	for(int i=0;i<2*NoOfVertices;i++)
	{
		NewCoordinate[i]=OldCoordinate[i];
	}

	for(int i=0;i<=2*NoOfVertices;i=i+2)
	{
		if((XYValue[2]>NewCoordinate[i+1]&&XYValue[2]<=NewCoordinate[i+3])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //Out-In Condition
		{
			OldCoordinate[pos]=(((XYValue[2]-NewCoordinate[i+1])*(NewCoordinate[i+2]-NewCoordinate[i]))/(NewCoordinate[i+3]-NewCoordinate[i+1]))+NewCoordinate[i];
			OldCoordinate[pos+1]=XYValue[2]; 
			OldCoordinate[pos+2]=NewCoordinate[i+2];
			OldCoordinate[pos+3]=NewCoordinate[i+3];
			pos+=4;
				
		}
		else if((XYValue[2]<NewCoordinate[i+1]&&XYValue[2]>NewCoordinate[i+3])&&i!=2*NoOfVertices && i!=2*NoOfVertices-2) //In-Out Condition
		{
			OldCoordinate[pos]=(((XYValue[2]-NewCoordinate[i+1])*(NewCoordinate[i+2]-NewCoordinate[i]))/(NewCoordinate[i+3]-NewCoordinate[i+1]))+NewCoordinate[i];   
			OldCoordinate[pos+1]=XYValue[2];
			pos+=2;
		}
		else if((XYValue[2]<=NewCoordinate[i+1]&&XYValue[2]<=NewCoordinate[i+3])&&i!=2*NoOfVertices&&i!=2*NoOfVertices-2) //In-In Condition
		{	
			OldCoordinate[pos]=NewCoordinate[i+2];
			OldCoordinate[pos+1]=NewCoordinate[i+3];  
			pos+=2;
		}
	    if(i==2*NoOfVertices) //Last To First Itaration
		{
			if((XYValue[2]<=NewCoordinate[1]&&XYValue[2]>NewCoordinate[i-1]))//out-in condition
			{
				OldCoordinate[pos]=(((XYValue[2]-NewCoordinate[1])*(NewCoordinate[i-2]-NewCoordinate[0]))/(NewCoordinate[i-1]-NewCoordinate[1]))+NewCoordinate[0];
				OldCoordinate[pos+1]=XYValue[2];
				OldCoordinate[pos+2]=NewCoordinate[0]; 
				OldCoordinate[pos+3]=NewCoordinate[1];
				pos+=4;
					
			}
			else if((XYValue[2]>NewCoordinate[1]&&XYValue[2]<NewCoordinate[i-1]))//In-out condition
			{
				OldCoordinate[pos]=(((XYValue[2]-NewCoordinate[1])*(NewCoordinate[i-2]-NewCoordinate[0]))/(NewCoordinate[i-1]-NewCoordinate[1]))+NewCoordinate[0];
				OldCoordinate[pos+1]=XYValue[2];   
				pos+=2;
			}
			else if((XYValue[2]<=NewCoordinate[1]&&XYValue[2]<=NewCoordinate[i-1]))//In-In Condition
			{	
				OldCoordinate[pos]=NewCoordinate[0];
				OldCoordinate[pos+1]=NewCoordinate[1];	
				pos+=2;
			}
		}
		count++;
	}
	cout<<"New Sequence:";
	for(int j=0;j<pos;j=j+2)
	{
		cout<<"("<<OldCoordinate[j]<<","<<OldCoordinate[j+1]<<")";
		Points[j]=int(OldCoordinate[j]);
		Points[j+1]=int(OldCoordinate[j+1]);
		if(j+2==pos)
		{	
			Points[j+2]=int(OldCoordinate[0]);
			Points[j+3]=int(OldCoordinate[1]);
		}
	}
	NoOfVertices=pos/2;	
	CartesianToGraphics();
	DrawGraph("B");
	cout<<endl<<endl;
	
}

void Sutherland_Hodgman()
{
	for(int i=0;i<4;i++)
	{
		if( ClipingOrder[i]=="L")
		{
			Left();
		}
		else if(ClipingOrder[i]=="R")
		{
			Right();
		}
		else if(ClipingOrder[i]=="T")
		{
			Top();
		}
		else if(ClipingOrder[i]=="B")
		{
			Bottom();
		}
	}
	
}

int main()
{
	int i=0,k=0,j=0,val;
	string str;
	float val2;
	ifstream read;
	read.open("in-1.txt",ios::in|ios::app);
	if(!read)
	{
		cout<<"File Not Found!!!";
	}
	else
	{
		while(!read.eof())
		{
			if(i>=0&&i<=3)
			{
			    read>>val;
				XYValue[i]=val;
			}	
		    else if(i>=4&&i<=7)
		    {
			     read>>str;
			     ClipingOrder[j]=str;
				 j++;	
			}
			else if(i==8)
			{
				 read>>val;
				 NoOfVertices=val;
			}
		    else{
		        read>>val2;
		        OldCoordinate[k]=val2;
		    	k++;
			}
			i++;
		}
		
		cout<<"Xmin="<<XYValue[0]<<endl;
		cout<<"Xmax="<<XYValue[1]<<endl;
		cout<<"Ymin="<<XYValue[2]<<endl;
		cout<<"Ymax="<<XYValue[3]<<endl;
		
		cout<<"Cliping Edge Sequence=";
		for(i=0;i<4;i++)
		{
			cout<<ClipingOrder[i]<<" ";
		}
		cout<<endl<<"No.Of Vertices In The Polygon="<<NoOfVertices<<endl;
		k=1;
		for(i=0;i<2*NoOfVertices;i=i+2)
		{   
			cout<<"P"<<k<<": ("<<OldCoordinate[i]<<","<<OldCoordinate[i+1]<<")"<<endl;
			k++;
		}
		CartesianToGraphics();
		for(i=0;i<Vertexcount;i++)
		{   
			StartCoordinate[i]=Points[i];
		}
		StartVertex=Vertexcount;
		XYConversion();
		cout<<endl;
		Sutherland_Hodgman();
	}	
}






