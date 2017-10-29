function createPlayerGrid(puzzleStr)
{
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++)
    {
      document.getElementById((""+i)+j).innerHTML = "1";
      iter++;
    }
  }
}
function createAIGrid(puzzleStr)
{
  puzzleArray = puzzleStr.split("")
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++, iter++)
    {
      var id = ("1"+i)+j;
      var val = puzzleArray[iter];
      if(val == "0") {
        document.getElementById(id).innerHTML = '-';
      } else {
        document.getElementById(id).innerHTML = val;
      }
    }
  }
}
