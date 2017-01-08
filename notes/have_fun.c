/* faehrni.ch/have-fun

I was looking through the book Expert C Programming again when I came upon
their "light relief" section on The International Obfuscated C Code
Competition. It's a contest to write the most obscure code. That the
language C has a competition where you write confusing code in it probably
says something about the language. I wanted to see how one of the entries to
this contest works. Not finding any explanation in Internet searches, I 
decided to investigate for myself.

The IOCCC was inspired by Steve Bournes decision to (ab)use the C preprocessor
when writing his Unix shell in a syntax of C more like Algol-68 with explicit
end statement cues where you have code like


    if
        ...
    fi


He achieved this with code similar to

  #define IF if(
  #define THEN ){
  #define ELSE } else {
  #define FI ;}

This let him write code like

  IF *s2++ == 0
  THEN return(0);
  FI

As Expert C says about this kind of code;

Shun any use of the C preprocessor that modifies the underlying language

One of the early winners in 1987 was a one-liner from David Korn, writer 
of the Korn shell (what's up with these shell writers):
*/


void main();

main(){printf(&unix["\021%six\012\0"], (unix)["have"]+"fun"-0x60);}


/* That's it. Go ahead and compile it. What does it print? */
