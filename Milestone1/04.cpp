// Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
// eg- if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.

string encode(string src)
{     
  //Your code here 
  string str="";
  int i,d=1;
  for(i=0;i<src.length()-1;i++)
  {
      if(src[i]==src[i+1])
      d++;
      else
      {
          str=str+src[i]+to_string(d);
          d=1;
      }
  }
  str=str+src[i]+to_string(d);
  return str;
}     

// Time Complexity: O(N), N = length of given string 'src'