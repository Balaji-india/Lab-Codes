#include <stdio.h>
#include <stdlib.h>
int *ht, m;
int count = 0;

void insert(int key){
  int idx = key%m;
  while(ht[idx]!=-1)
    idx = (idx+1)%m;
  ht[idx] = key;
  count++;
}

void display(){
  if(count==0){
    printf("The Hash Table is empty");
    return;
  }
  printf("Hash Table Contents: \n");
  for(int i=0;i<m;i++)
    printf("\nht[%d] -> %d",i,ht[i]);
}

int main(){
  FILE *fp;
  int key,n;
  printf("Enter the number of records: ");
  scanf("%d", &n);
  printf("Enter the two digit memory location for hash table: ");
  scanf("%d", &m);
  ht = (int*)malloc(m*sizeof(int));
  for(int i=0;i<m;i++){
    ht[i] = -1;
  }
  fp = fopen("a.txt","r");
  for(int i=0;i<n;i++){
    if(count==m){
      printf("Hash Table is full");
      break;
    }
    else{
      fscanf(fp, "%d", &key);
      insert(key);
    }
  }
  display();
  return 0;
}
