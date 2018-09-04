void parti(int *arr,size_t left,size_t right)
{
	size_t mid  = (left+right)/2;
	if(arr[left]>arr[right])
	{
		swap(arr[left],arr[right]);
	}
	if(arr[mid]>arr[right])
	{
		swap(arr[mid],arr[right]);
	}
	if(arr[left]<arr[mid])
	{
		swap(arr[left],arr[mid]);
	}
}

void qsort(int *arr, size_t left, size_t right)
{
	if (left >= right)
		return;
	else if(right-left == 1)
	{
		if(arr[right]<arr[left])
			swap(arr[right],arr[left]);
	}
	parti(arr,left,right);
	size_t i = left;
	size_t j = right;
	int temp = arr[left];
	while(i!=j)
	{
		while(i<j && arr[j]>temp)
			--j;
		while(arr[i]<=temp && i<j)
			++i;
		if(i < j)
		{
			swap(arr[i],arr[j]);
		}
	}
	arr[left] = arr[i];
	arr[i]   = temp;

	size_t pval = i;
	size_t k1=left,k2=pval;
	while(k1!=k2)
	{
		while(k1<k2 && arr[k2]==temp)
			--k2;
		while(k1<k2 && arr[k1]!=temp)
			++k1;
		if(k1<k2)
		{
			swap(arr[k1],arr[k2]);
		}
	}
	if(k2!=left)
	{
		if(arr[k2]==temp)
			qsort(arr,left,k2-1);
		else
			qsort(arr,left,k2);
	}
	qsort(arr,pval+1,right);
	return;

}

void quicksort(int *arr, size_t dsize)
{
	size_t left = 0;
	size_t right= dsize-1;
	qsort(arr,left,right);
}

