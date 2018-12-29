#include<string>
#include<vector>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Record{
	string host_id;
	string unfilled;
	float score;
	string city;
	int split(vector<string> &out, const string &in, const string &seps){
		const char *instr=in.c_str();
		char *s=strdup(instr);
		const char *sep = seps.c_str();
		char *p=nullptr;
		for(p=strsep(&s, sep) ; p!=nullptr; p=strsep(&s,sep)){
			out.push_back(p);
		}
		free(s);
		return 0;
	}

	void from_string(const string &str){
		vector<string> lists;
		split(lists, str, ",");
		host_id = lists[0];
		unfilled = lists[1];
		score=strtof(lists[3].c_str(), nullptr);
		city = lists[4];
		str_ = str;
	}
	string str_;
};
struct CompByScore;
struct Page;
struct HostInfo;

struct CompByScore{
	bool operator()( Record &x, Record &y){
		return x.score > y.score;
	}
}combyscore;

struct Page{
	int num_;
	set<string> hosts;
	vector<Record> lines;
	void sort(){
		std::sort(lines.begin(), lines.end(), combyscore);
	}
	size_t size(){
		return lines.size();
	}
	void append(Record line){
		lines.push_back(line);
		hosts.insert(line.host_id);
	}
	bool has(string host_id){
		return hosts.find(host_id) != hosts.end();
	}
	void clear(){
		hosts.clear();
		lines.clear();
	}
	bool full(){
		return num_ == lines.size();
	}
	Page( int num):num_(num){ }
};


struct HostInfo{
	string host_id;
	deque<Record> records;
	size_t size(){
		return records.size();
	}
	void append(Record r){
		records.push_back(r);
		host_id=r.host_id;
	};
	void pop_front(){
		records.pop_front();
	};

	/* bool operator< (HostInfo &x, HostInfo &y){ */
		/* return x.size() < y.size(); */
	/* } */
	bool operator() (HostInfo &x, HostInfo &y){
		return x.size() > y.size();
	}
} hostinfo;

typedef std::map<string, HostInfo> Buckets;
typedef std::vector<HostInfo> VBuckets;


vector <string> paginate(int num, vector <string> results) {
	vector<string> ans;
	Buckets buckets;
	int ans_index =0, total=0;
	for(auto line:results){
		Record record;
		record.from_string(line);
		buckets[record.host_id].append(record);
		total ++;
	}
    VBuckets input;
	for(auto &bucket:buckets){
		input.push_back(bucket.second);
	}
	sort(input.begin(), input.end(), hostinfo); 

	Page page(num);
	for(int i=0;i<total; i++){
		//find the record to be filled.
		int index = 0;
		for(auto host:input){
			if(!page.has(host.host_id) ){
					break;
			}
			index ++;
		}	
		if(index >= input.size()) index = 0;
		//fill in the page.
		page.append(input[index].records.front());
		if(page.full()){
			page.sort();	
			for(int i=0;i<page.size();i++) {
					ans.push_back(page.lines[i].str_);
			}
			ans.push_back("");
		}
		//remove the record from input and update input.
		input[index].pop_front();	
		//update
		if(input[index].size() == 0) input.erase(input.begin() + index);
		else sort(input.begin(), input.end(), hostinfo);
	}
	if(!page.full()){
			page.sort();	
			for(int i=0;i<page.size();i++){
					ans.push_back(page.lines[i].str_);
			}
	}
	return ans;
}

int main(int argc, char *argv[])
{
	/* code */
	vector<string> input;
	int num=2;
	paginate(num,input);
	return 0;
}
