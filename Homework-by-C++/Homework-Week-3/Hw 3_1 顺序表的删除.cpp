List Delete( List &L, ElementType minD, ElementType maxD ){
    for(int i =0;i<=L.last;i++){
        if(L.Data[i]<minD){
            for(int j = i;j<=L.last;j++){
                L.Data[j]=L.Data[j+1];
            }
            L.Data[L.last]=0;
            L.last--;
            i--;
        }
        if(L.Data[i]>maxD){
            for(int j = i;j<=L.last;j++){
                L.Data[j]=L.Data[j+1];
            }
            L.Data[L.last]=0;
            L.last--;
        }
    }
   for(int i=0;i<=L.last;i++)
     {
          printf("%d ",L.Data[i]);
   }
}