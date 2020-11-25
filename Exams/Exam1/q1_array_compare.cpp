bool array_compare(int A[], unsigned int size_A, int B[], unsigned int size_B) {

  bool indicator = false;

  for(unsigned int i = 0; i < size_A; i++)
  {
    if(A[i] < B[i])
    {
      indicator = true;
      return true;
    }
    if(indicator == false && size_A < size_B)
    {
      return true;
    }
  }


    return false;
}
