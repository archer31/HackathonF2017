function createPLayerGrid()
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
function createAIGrid()
{
  var iter=0;
  for(var i=1; i<=9; i++)
  {
    for(var j=1; j<=9; j++)
    {
      document.getElementById(("1"+i)+j).innerHTML = "1";
      iter++;
    }
  }
}
