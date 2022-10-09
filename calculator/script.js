// Todo: Make M+ M- and MC functional
let final_ans = "";
let j=0;
let result_generated=0;
let buttons = document.querySelectorAll('.button');
Array.from(buttons).forEach((button)=>{
  button.addEventListener('click', (e)=>{
    if(e.target.innerHTML == '='){
      string = eval(string);
      document.querySelector('input').value = string;
      result_generated=1;
      j=string.length; 
    }
    else if(e.target.innerHTML == 'C'){
      string = ""
      document.querySelector('input').value = string;
      result_generated=0;
    }
    else{ 
    console.log(e.target)
    string = string + e.target.innerHTML;
    document.querySelector('input').value = string;
      j=string.length;                                                                           
      }
  })
})

// to add the correct/clear function
let clr=document.getElementById('onlyforclear');
clr.addEventListener('click', ()=>{ 
   if(result_generated==1)
     {document.querySelector('input').value = "";
   result_generated=0;
      string="";
 }
   else {
   var str=string.substr(0, j-1); 
    document.querySelector('input').value = str;
    string=str;   
   j--;   // removing the last element
 }
});