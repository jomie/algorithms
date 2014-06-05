int calc_utf8_count(unsigned char* data_ptr,unsigned int data_len )
{ 
	assert(data_ptr!=NULL && data_len>0); 
        int count=0;
	for(int i=0;i<data_len;++i)
	{
      	if(!(data_ptr[i]&0x80))
	  	{
		  count++;
		  continue;
          
	  	}
	  	else if (data_len-1-i>=1  &&  ((data_ptr[i]>>7)&(data_ptr[i]>>6)&( (data_ptr[i]>>5)^0x01 )&0x01)  && (  (data_ptr[i+1]>>7) & (data_ptr[i+1]>>6^0x01) ))
	  	{
	   	count++;
	   	i=i+1;
       	continue;	
	  }
	  else if(data_len-1-i>=2  &&(  (data_ptr[i]>>7)&(data_ptr[i]>>6)& (data_ptr[i]>>5)& 0x01 &data_ptr[i]>>4^0x01 )  &&   ( (data_ptr[i+1]>>7) & (data_ptr[i+1]>>6^0x01) )  &&  ((data_ptr[i+2]>>7) & (data_ptr[i+2]>>6^0x01) ) )
	  {
	   count++;
	   i=i+2;
	   continue;
	  }
	  else
	  {
	   count=-1;//不是utf8字节流
	   break;
	  }
	}
	return count;
}
