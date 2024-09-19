int find(int A[],int x)
{
      if(A[x]==x)return x;
      return A[x] = find(A,A[x]);
}
void unionSet(int A[],int x,int z)
{
    int parentz = find(A,z);
    int parentx = find(A,x);
	A[parentx] = parentz;
}
