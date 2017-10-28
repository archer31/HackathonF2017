//Jake Hanson, Ryan Lynn, Xandy Corley

var difficulty;
var numbers

function newGame()
{
  numbers=getNumbers();
  makeGrid();
}

function getNumbers()
{
  var fail = false;
  var array = [1, 2, 3, 4, 5, 6, 7, 8, 9];
  var temp = FY_Shuffle(array);
  for(var i=0; i<9; i++)
  {
    for(var j=0; j<Math.floor(numbers.length/9); j++)
    {
      if(numbers[i] == numbers[(j*9)+i])
      {
        fail = true;
        break;
      }
    }
    if(fail){break;}
  }
  if(fail||numbers.length<81)
  {
    if(!fail)
    {
      for(var i=0; i<9; i++)
      {
        numbers.push(array[i]);
      }
    }
    return getNumbers();
  }
  for(var i=0; i<9; i++)
  {
    numbers.push(array[i];
  }
  return;
}

function makeGrid()
{
  for(var h=0; h<81; h++)
  {
    for(var i=1; i<=9; i++)
    {
      for(var j=1; j<=9; j++)
      {
        document.getElementById(i+j).value = numbers[h];
      }
    }
  }
  Math.floor(Math.random()*512)
}



//Fisher-Yates Shuffle adapted from htps://bost.ocks.org/mike/shuffle/
function FY_Shuffle(array)
{
  var m = array.length, t, i;
  //While there remain elements to shuffle
  while (m)
  {
    //Pick a remaining element
    i = Math.floor(Math.random() * m--);
    //And swap it with the current element
    t = array[m];
    array[m] = array[i];
    array[i] = t;
  }
  return array;
}
