/*
 * swea 3135: 홍준이의 사전놀이
 * copyright: nsj6646@naver.com
 */

#define ALPHA   26
#define MAXN    100000
struct Trie{
    bool term;
    int cnt;
    Trie* next[ALPHA];
    Trie(){
        init();
    }
    void init(){
        term=false;
        cnt=0;
        for(int i=0;i<ALPHA;++i){
            next[i]=0;
        }
    }
}triePool[51][MAXN*10];
int tc=0;
int trieIdx=0;
Trie* newTrie() {return &triePool[tc][trieIdx++];}

Trie *root;
void init(void) {
    tc++;
    root=0;
    trieIdx=0;
}

void insert(int buffer_size, char *buf) {
    if(!root){ 
        root=newTrie();
    }
    Trie *cur=root;

    for(int i=0;i<buffer_size;++i){
        int idx=buf[i]-'a';
        if(cur->next[idx]==0){
            cur->next[idx]=newTrie();
        }
        cur=cur->next[idx];
        cur->cnt++;
    }
    cur->term=true;
}

int query(int buffer_size, char *buf) {
    if(!root){
        return 0;
    }

    Trie *cur=root;
    for(int i=0;i<buffer_size;++i){
        int idx=buf[i]-'a';
        if(cur->next[idx]==0){
            return 0;
        }
        cur=cur->next[idx];
    }
	return cur->cnt;
}