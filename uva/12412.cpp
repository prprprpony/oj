#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

typedef struct 
{
	long long sid;
	int cid,score[4],total,total_passed;
	double average;
	string name;
	bool passed[4];
} info;

typedef struct
{
	int total_score[4],
	    subject_passed[4],
	    num_people,
	    people_passed_num[5];
} stat;

vector<info> student;
map<long long,int> SIDtoRank;
stat classes[25]={0};

long long atoll(string str)
{
	long long num=0;
	for( int i=0 ; i<str.size() ; i++ )
	{
		if( isdigit(str[i]) )
		{
			num*=10;
			num+=(str[i]-'0');
		}
	}
	
	return num;
}

vector<info>::iterator search(vector<info>::iterator it,string in)
{
	if( isdigit(in[0]) )
	{
		long long sid=atoll(in);
		for(;it!=student.end();it++)
			if(it->sid==sid)break;
	}
	else
	{
		for(;it!=student.end();it++)
                        if(it->name==in)break;
	}
	
	return it;
}

int GetSIDorName(string &in,string help)
{
	cout<<help<<endl;
	cin>>in;
	if( in.size()==1 && in[0]=='0')return 0;
	else return 1;
}

bool cmp(info a,info b)
{
	return a.total>b.total;
}

void rank()
{

	vector<info> tmp=student;
	sort(tmp.begin(),tmp.end(),cmp);

	SIDtoRank[tmp[0].sid]=1;
	for(int i=1;i<tmp.size();i++)
		SIDtoRank[tmp[i].sid]=(tmp[i].total==tmp[i-1].total)?SIDtoRank[tmp[i-1].sid]:i+1;

}

void menu()
{
        cout<<"Welcome to Student Performance Management System (SPMS)."<<endl;
        cout<<endl;
        cout<<"1 - Add"<<endl;
        cout<<"2 - Remove"<<endl;
        cout<<"3 - Query"<<endl;
        cout<<"4 - Show ranking"<<endl;
        cout<<"5 - Show Statistics"<<endl;
        cout<<"0 - Exit"<<endl;
	cout<<endl;

	return;
}

void add()
{
	info in;
	string sid,help="Please enter the SID, CID, name and four scores. Enter 0 to finish.";
	
	while(GetSIDorName(sid,help))
	{
		in.sid = atoll( sid );
                cin>>in.cid>>in.name;
                in.total=0;
		in.total_passed=0;
                for(int i=0;i<4;i++)
                	cin>>in.score[i];
       
                if( search( student.begin() , sid ) != student.end() )
                {cout<<"Duplicated SID."<<endl;continue;}
                
		stat *C= &classes[in.cid];
		C->num_people++;

                for(int i=0;i<4;i++)
		{
                        in.total+=in.score[i];
                        in.passed[i]=(in.score[i]>=60);

                        if(in.passed[i])
			{
				in.total_passed++;
				C->subject_passed[i]++;
			}
			C->total_score[i]+=in.score[i];
		}
                in.average=(in.total/4.0)+1e-5;

		C->people_passed_num[in.total_passed]++;
                student.push_back(in);
	}

	return;
}

void remove()
{
	string in,help="Please enter SID or name. Enter 0 to finish.";
	
	while( GetSIDorName(in,help) )
	{

                vector<info>::iterator it=student.begin();
		int num_removed=0;

                while( (it=search(it,in)) != student.end() ) 
		{
			stat *C=&classes[it->cid];
			C->num_people--;
			C->people_passed_num[it->total_passed]--;
			for(int i=0;i<4;i++)
			{
				C->total_score[i]-=it->score[i];
				if(it->passed[i])
					C->subject_passed[i]--;
				
			}
			
			SIDtoRank[it->sid]=0;
			SIDtoRank.erase(it->sid);
                        student.erase(it);
                	num_removed++;
                }
                        
		cout<<num_removed<<" student(s) removed."<<endl;

	}

	return;
}

void query()
{
	string in,help="Please enter SID or name. Enter 0 to finish.";
	
        while( GetSIDorName(in,help) )
	{
		bool ranked=false;
                vector<info>::iterator it=student.begin();
		
                while( (it=search(it,in)) != student.end() )
		{
			if(!ranked)
			{
				rank();
				ranked=true;
			}

			cout<<SIDtoRank[it->sid]<<" ";
			printf("%010lld ",it->sid);
			cout<<it->cid<<" "<<it->name<<" ";
			for(int i=0;i<4;i++)
				cout<<it->score[i]<<" ";
			cout<<it->total<<" ";
			printf("%.2f\n",it->average);
			
			it++;
		}

	}

	return;
}

void stats()
{
	cout<<"Please enter class ID, 0 for the whole statistics."<<endl;
	string sub[4]={"Chinese","Mathematics","English","Programming"};
	int cid;
	cin>>cid;
	stat *C=&classes[cid];
	
	if(cid==0)
	{
		memset( C , 0 , sizeof(stat) );
		for(stat *it=&classes[1] ; it!=( classes + sizeof(classes) / sizeof(stat) ) ; it++)
		{
			if(it->num_people)
			{
				C->num_people+=it->num_people;
				for(int i=0;i<4;i++)
				{
					C->total_score[i]+=it->total_score[i];
					C->subject_passed[i]+=it->subject_passed[i];
					C->people_passed_num[i]+=it->people_passed_num[i];
				}
				C->people_passed_num[4]+=it->people_passed_num[4];

			}
		}
	}

	for(int i=0;i<4;i++)
	{
		cout<<sub[i]<<endl;
		cout.precision(2);
		cout<<fixed;
		cout<<"Average Score: "<<C->total_score[i]/(double)C->num_people+1e-5<<endl;
		cout<<"Number of passed students: "<<C->subject_passed[i]<<endl;
		cout<<"Number of failed students: "<< C->num_people - C->subject_passed[i]<<endl;
		cout<<endl;
	}
	
	string overall[5]=
	{
		"Number of students who passed all subjects: ",
		"Number of students who passed 3 or more subjects: ",
		"Number of students who passed 2 or more subjects: ",
		"Number of students who passed 1 or more subjects: ",
		"Number of students who failed all subjects: "
	};

	cout<<"Overall:"<<endl;
	int passed_num=0;
	for(int i=0;i<5;i++)
	{
		if(i!=4)passed_num+=C->people_passed_num[4-i];
		else passed_num=C->people_passed_num[0];

		cout<<overall[i]<<passed_num<<endl;
	}
	cout<<endl;
	
	return;
}

int main()
{
	int o=-1;
	do
	{
		switch(o)
		{
			case 1:
				add();
				break;
			case 2:
				remove();
				break;
			case 3:
				query();
				break;
			case 4:
				cout<<"Showing the ranklist hurts students' self-esteem. Don't do that."<<endl;
				break;
			case 5:
				stats();
				break;	

			default:
				break;
		}
	
		menu();

	}while( cin>>o && o!=0);

	return 0;
}
