<HTML>
	<HEAD>
		<TITLE>
			C PUZZLES, Some interesting C problems
		</TITLE>
	</HEAD>
	<body>


<p align="center">
<a href="http://www.gowrikumar.com"> <img src="../common/logo.gif" alt="Go to www.gowrikumar.com main page" align="center"> </a>
</p>

Share this page :
<!-- AddToAny BEGIN -->
<div class="a2a_kit a2a_kit_size_32 a2a_default_style">
<a class="a2a_dd" href="http://www.addtoany.com/share_save?linkurl=/c/index.php;linkname="></a>
<a class="a2a_button_reddit"></a>
<a class="a2a_button_linkedin"></a>
<a class="a2a_button_facebook"></a>
<a class="a2a_button_twitter"></a>
<a class="a2a_button_google_plus"></a>
<a class="a2a_button_digg"></a>
</div>
<script type="text/javascript">
var url = /c/index.php;
var a2a_config = a2a_config || {};
a2a_config.linkurl = url";
</script>
<script type="text/javascript" src="http://static.addtoany.com/menu/page.js"></script>
<!-- AddToAny END -->


<script async src="http://pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- first ad -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-3469254531473816"
     data-ad-slot="6641100684"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>
<p>

		<h3>Dear visitor,</h3>
		Thanks for your interest in C programming.
		In this page, you will find a 
		list of interesting C programming questions/puzzles, 
		These programs listed are the ones which I have received as
		e-mail forwards from my friends, a few I read in some books, a few from the
   		internet, and a few from  my coding experiences in C.
		<p>
		Most of the programs are meant to be compiled, run and
		to be explained  for their behaviour. The puzzles/questions can be broadly 
		put into the following categories:
		<ul>
		<li>
		 General typo errors, which C programmers do often and are 
		 very difficult to trace.
		</li>

		<li>
		Small programs which are extremely hard to understand at the first
		examination. These questions make a good excercise of reading and understanding
		effecient code written by others.
		</li>
		</ul>

	
		<p>
		I have used Gnu/Linux/gcc for all of them. 
		The order in which the programs appear doesn't have
		any relation with the level of difficulty.

		Please feel free to contact me if you need any help in solving the problems.
		My contact info. is available <a href="http://www.gowrikumar.com/contact.html">here</a>
		And you might be interested in a few <a href="http://www.gowrikumar.com/c/references.html">references for C programming</a>, 
		which I personally found very interesting.

<BR>
<p>
If you are preparing for campus interviews, you might find the following
link interesting:<BR>
<a href="http://placementsindia.blogspot.com">http://placementsindia.blogspot.com</a><BR>
<a href="http://www.interviewmantra.net/category/interview-questions/c">http://www.interviewmantra.net/category/interview-questions/c</a><BR>
<BR>
<BR>
Regards,<BR>
<i>Gowri Kumar</i>
<BR>
<BR>

<h1>C puzzles</h1>
<hr>
The expected output of the following C program
is to print the elements in the array. But when
actually run, it doesn't do so.
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">TOTAL_ELEMENTS </font><font
 color="#a020f0">(</font><font color="#a52a2a"><b>sizeof</b></font><font
 color="#a020f0">(</font><font color="#008b8b">array</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>/</b></font><font
 color="#a020f0"> </font><font color="#a52a2a"><b>sizeof</b></font><font
 color="#a020f0">(</font><font color="#008b8b">array</font><font
 color="#a020f0">[</font><font color="#a020f0">0</font><font
 color="#a020f0">]))</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">array</font>[] <font color="#a52a2a"><b>=</b></font> {<font
 color="#ff00ff">23</font>,<font color="#ff00ff">34</font>,<font
 color="#ff00ff">12</font>,<font color="#ff00ff">17</font>,<font
 color="#ff00ff">204</font>,<font color="#ff00ff">99</font>,<font
 color="#ff00ff">16</font>};<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">d</font>;<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>for</b></font>(<font
 color="#008b8b">d</font><font color="#a52a2a"><b>=-</b></font><font
 color="#ff00ff">1</font>;<font color="#008b8b">d</font> <font
 color="#a52a2a"><b>&lt;=</b></font> (<font color="#008b8b">TOTAL_ELEMENTS</font><font
 color="#a52a2a"><b>-</b></font><font color="#ff00ff">2</font>);<font
 color="#008b8b">d</font><font color="#a52a2a"><b>++</b></font>)<br><font
 color="#000000"></font>          <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">array</font>[<font color="#008b8b">d</font><font
 color="#a52a2a"><b>+</b></font><font color="#ff00ff">1</font>]);<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
Find out what's going wrong.<br>
<a href="http://www.gowrikumar.com/c/hints/arr.html">hint</a><br>
<p>



<hr>
I thought the following program was a perfect C program. But on 
compiling, I found a silly mistake. Can you find it out (without
compiling the program :-) ?
<pre>
<font color="#a020f0">#include</font><font color="#ff00ff">&lt;stdio.h&gt;</font>

<font color="#2e8b57"><b>void</b></font> <font color="#008b8b">OS_Solaris_print</font>()
{
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;Solaris - Sun Microsystems</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);
}

<font color="#2e8b57"><b>void</b></font> <font color="#008b8b">OS_Windows_print</font>()
{
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;Windows - Microsoft</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);

}
<font color="#2e8b57"><b>void</b></font> <font color="#008b8b">OS_HP-UX_print</font>()
{
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;HP-UX - Hewlett Packard</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);
}

<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">num</font>;
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;Enter the number (1-3):</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);
        <font color="#008b8b">scanf</font>(<font color="#ff00ff">&quot;</font><font color="#6a5acd">%d</font><font color="#ff00ff">&quot;</font>,<font color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">num</font>);
        <font color="#a52a2a"><b>switch</b></font>(<font color="#008b8b">num</font>)
        {
                <font color="#a52a2a"><b>case</b></font> <font color="#ff00ff">1</font>:
                        <font color="#008b8b">OS_Solaris_print</font>();
                        <font color="#a52a2a"><b>break</b></font>;
                <font color="#a52a2a"><b>case</b></font> <font color="#ff00ff">2</font>:
                        <font color="#008b8b">OS_Windows_print</font>();
                        <font color="#a52a2a"><b>break</b></font>;
                <font color="#a52a2a"><b>case</b></font> <font color="#ff00ff">3</font>:
                        <font color="#008b8b">OS_HP-UX_print</font>();
                        <font color="#a52a2a"><b>break</b></font>;
                <font color="#a52a2a"><b>default</b></font>:
                        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;Hmm! only 1-3 :-)</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);
                        <font color="#a52a2a"><b>break</b></font>;
        }

        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>
<a href="http://www.gowrikumar.com/c/hints/ident.html">hint</a><br>

<hr>
<table width=100%>
<tr>
<td>
What's the expected output for the following program and why?
<pre>
<font color="#2e8b57"><b>enum</b></font> {<font color="#008b8b">false</font>,<font color="#008b8b">true</font>};

<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">i</font><font color="#a52a2a"><b>=</b></font><font color="#ff00ff">1</font>;
        <font color="#a52a2a"><b>do</b></font>
        {
                <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;</font><font color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">i</font>);
                <font color="#008b8b">i</font><font color="#a52a2a"><b>++</b></font>;
                <font color="#a52a2a"><b>if</b></font>(<font color="#008b8b">i</font> <font color="#a52a2a"><b>&lt;</b></font> <font color="#ff00ff">15</font>)
                        <font color="#a52a2a"><b>continue</b></font>;
        }<font color="#a52a2a"><b>while</b></font>(<font color="#008b8b">false</font>);
        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>
<a href="http://www.gowrikumar.com/c/hints/continue.html">hint</a><br>
<hr> 
The following program doesn't "seem" to print "hello-out".
(Try executing it)
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;unistd.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>while</b></font>(<font
 color="#ff00ff">1</font>)<br><font color="#000000"></font>          {<br><font
 color="#000000"></font>                  <font color="#008b8b">fprintf</font>(<font
 color="#ff00ff">stdout</font>,<font color="#ff00ff">"hello-out"</font>);<br><font
 color="#000000"></font>                  <font color="#008b8b">fprintf</font>(<font
 color="#ff00ff">stderr</font>,<font color="#ff00ff">"hello-err"</font>);<br><font
 color="#000000"></font>                  <font color="#008b8b">sleep</font>(<font
 color="#ff00ff">1</font>);<br><font color="#000000"></font>          }<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
What could be the reason?<br>
<hr>
</td>

</tr>
</table>

<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">f</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">,</font><font color="#008b8b">b</font><font
 color="#a020f0">) </font><font color="#008b8b">a</font><font
 color="#a52a2a"><b>##</b></font><font color="#008b8b">b</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">g</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">)   </font><font color="#a52a2a"><b>#</b></font><font
 color="#008b8b">a</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">h</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">) </font><font color="#008b8b">g</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">)</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%s</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">h</font>(<font color="#008b8b">f</font>(<font
 color="#ff00ff">1</font>,<font color="#ff00ff">2</font>)));<br><font
 color="#000000"></font>          <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%s</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">g</font>(<font color="#008b8b">f</font>(<font
 color="#ff00ff">1</font>,<font color="#ff00ff">2</font>)));<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
Just by looking at the program one "might" expect the output to be, the
same for both the printf statements. But on running the program you get
it as:
<br>
bash$ ./a.out<br>
12<br>
f(1,2)<br>
bash$<br>
<br>
Why is it so?<br>
<a href="http://www.gowrikumar.com/c/hints/macro.html">hint</a><br>
<hr>
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font><font color="#a52a2a"><b>=</b></font><font
 color="#ff00ff">10</font>;<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>switch</b></font>(<font color="#008b8b">a</font>)<br><font
 color="#000000"></font>          {<br><font color="#000000"></font>                  <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">'1'</font>:<br><font
 color="#000000"></font>                      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"ONE</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>                      <font
 color="#a52a2a"><b>break</b></font>;<br><font color="#000000"></font>                  <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">'2'</font>:<br><font
 color="#000000"></font>                      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"TWO</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>                      <font
 color="#a52a2a"><b>break</b></font>;<br><font color="#000000"></font>                  <font
 color="#a52a2a"><b>defa1ut</b></font>:<br><font color="#000000"></font>                      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"NONE</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>          }<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
If you expect the output of the above program to be
<b>NONE</b>, I would request you to check it out!!<br>
<hr>
The following C program segfaults of IA-64, but works fine on
IA-32.
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font><font
 color="#a52a2a"><b>*</b></font> <font color="#008b8b">p</font>;<br><font
 color="#000000"></font>      <font color="#008b8b">p</font> <font
 color="#a52a2a"><b>=</b></font> (<font color="#2e8b57"><b>int</b></font><font
 color="#a52a2a"><b>*</b></font>)<font color="#008b8b">malloc</font>(<font
 color="#a52a2a"><b>sizeof</b></font>(<font color="#2e8b57"><b>int</b></font>));<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">p</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">10</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
Why does it happen so?<br>
<hr>



<hr>
Here is a small piece of program(again just 14 lines of program)
which counts the number of bits set in a number.<br>
<table>
  <tbody>
    <tr>
      <td> Input </td>
      <td> Output </td>
    </tr>
    <tr>
      <td> 0 </td>
      <td> 0(0000000) </td>
    </tr>
    <tr>
      <td> 5 </td>
      <td> 2(0000101) </td>
    </tr>
    <tr>
      <td> 7 </td>
      <td> 3(0000111) </td>
    </tr>
  </tbody>
</table>
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">CountBits </font>(<font color="#2e8b57"><b>unsigned</b></font> <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">x</font> )<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>static</b></font> <font color="#2e8b57"><b>unsigned</b></font> <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">mask</font>[] <font
 color="#a52a2a"><b>=</b></font> { <font color="#ff00ff">0x55555555</font>,<br><font
 color="#000000"></font>          <font color="#ff00ff">0x33333333</font>,<br><font
 color="#000000"></font>          <font color="#ff00ff">0x0F0F0F0F</font>,<br><font
 color="#000000"></font>          <font color="#ff00ff">0x00FF00FF</font>,<br><font
 color="#000000"></font>          <font color="#ff00ff">0x0000FFFF</font>
<font color="#000000"></font>          } ;<br><font color="#000000"></font>
<font color="#000000"></font>          <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">i</font> ;<br><font color="#000000"></font>          <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">shift</font> ; <font
 color="#0000ff">/* Number of positions to shift to right*/</font>
<font color="#000000"></font>          <font color="#a52a2a"><b>for</b></font> ( <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>=</b></font><font
 color="#a020f0">0</font>, <font color="#008b8b">shift</font> <font
 color="#a52a2a"><b>=</b></font><font color="#ff00ff">1</font>; <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>&lt;</b></font> <font
 color="#ff00ff">5</font>; <font color="#008b8b">i</font> <font
 color="#a52a2a"><b>++</b></font>, <font color="#008b8b">shift</font> <font
 color="#a52a2a"><b>*=</b></font> <font color="#ff00ff">2</font>)<br><font
 color="#000000"></font>                  <font color="#008b8b">x</font> <font
 color="#a52a2a"><b>=</b></font> (<font color="#008b8b">x</font> <font
 color="#a52a2a"><b>&amp;</b></font> <font color="#008b8b">mask</font>[<font
 color="#008b8b">i</font> ])<font color="#a52a2a"><b>+</b></font> ( ( <font
 color="#008b8b">x</font> <font color="#a52a2a"><b>&gt;&gt;</b></font> <font
 color="#008b8b">shift</font>) <font color="#a52a2a"><b>&amp;</b></font> <font
 color="#008b8b">mask</font>[<font color="#008b8b">i</font>]);<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>return</b></font> <font
 color="#008b8b">x</font>;<br><font color="#000000"></font>  }<br></pre>
Find out the logic used in the above program.
<hr>
What do you think would be the output of the following program and
why? (If you are about to say "f is 1.0", I would say check it out again)
<pre>
<font color="#a020f0">#include</font><font color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>

<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#2e8b57"><b>float</b></font> <font color="#008b8b">f</font><font color="#a52a2a"><b>=</b></font><font color="#ff00ff">0.0f</font>;
        <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">i</font>;

        <font color="#a52a2a"><b>for</b></font>(<font color="#008b8b">i</font><font color="#a52a2a"><b>=</b></font><font color="#a020f0">0</font>;<font color="#008b8b">i</font><font color="#a52a2a"><b>&lt;</b></font><font color="#ff00ff">10</font>;<font color="#008b8b">i</font><font color="#a52a2a"><b>++</b></font>)
                <font color="#008b8b">f</font> <font color="#a52a2a"><b>=</b></font> <font color="#008b8b">f</font> <font color="#a52a2a"><b>+</b></font> <font color="#ff00ff">0.1f</font>;

        <font color="#a52a2a"><b>if</b></font>(<font color="#008b8b">f</font> <font color="#a52a2a"><b>==</b></font> <font color="#ff00ff">1.0f</font>)
                <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;f is 1.0 </font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);
        <font color="#a52a2a"><b>else</b></font>
                <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;f is NOT 1.0</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>);

        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>

<hr>
I thought the following C program is perfectly valid (after reading about
the comma operator in C).
But there is a mistake in the following program, can you identify it?

<pre>
<font color="#a020f0">#include</font><font color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>

<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">a</font> <font color="#a52a2a"><b>=</b></font> <font color="#ff00ff">1</font>,<font color="#ff00ff">2</font>;
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;a : </font><font color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">a</font>);
        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>
<hr>
What would be the output of the following C program?
(Is it a valid C program?)
<pre>
<font color="#a020f0">#include</font><font color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">i</font><font color="#a52a2a"><b>=</b></font><font color="#ff00ff">43</font>;
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;</font><font color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;</font><font color="#6a5acd">%d</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;</font><font color="#6a5acd">%d</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">i</font>)));
        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>

<hr>
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">duff</font>(<font color="#2e8b57"><b>register</b></font> <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">to</font>, <font color="#2e8b57"><b>register</b></font> <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">from</font>, <font color="#2e8b57"><b>register</b></font> <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">count</font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>register</b></font> <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">n</font><font color="#a52a2a"><b>=</b></font>(<font
 color="#008b8b">count</font><font color="#a52a2a"><b>+</b></font><font
 color="#ff00ff">7</font>)<font color="#a52a2a"><b>/</b></font><font
 color="#ff00ff">8</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>switch</b></font>(<font color="#008b8b">count</font><font
 color="#a52a2a"><b>%</b></font><font color="#ff00ff">8</font>){<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>case</b></font> <font
 color="#a020f0">0</font>: <font color="#a52a2a"><b>do</b></font>{ <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">7</font>:  <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">6</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">5</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">4</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">3</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">2</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">1</font>: <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">to</font><font
 color="#a52a2a"><b>++</b></font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">from</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>              }<font
 color="#a52a2a"><b>while</b></font>( <font color="#a52a2a"><b>--</b></font><font
 color="#008b8b">n</font> <font color="#a52a2a"><b>&gt;</b></font><font
 color="#a020f0">0</font>);<br><font color="#000000"></font>      }<br><font
 color="#000000"></font>  }<br></pre>
Is the above valid C code? If so, what is it trying to acheive
and why would anyone do something like the above?
<hr>Here is yet another implementation of CountBits.
Verify whether it is correct (how do you that???). If so, find out the
logic
used.
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">CountBits</font>(<font color="#2e8b57"><b>unsigned</b></font> <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">x</font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">count</font><font
 color="#a52a2a"><b>=</b></font><font color="#a020f0">0</font>;<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>while</b></font>(<font
 color="#008b8b">x</font>)<br><font color="#000000"></font>      {<br><font
 color="#000000"></font>          <font color="#008b8b">count</font><font
 color="#a52a2a"><b>++</b></font>;<br><font color="#000000"></font>          <font
 color="#008b8b">x</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">x</font><font color="#a52a2a"><b>&amp;</b></font>(<font
 color="#008b8b">x</font><font color="#a52a2a"><b>-</b></font><font
 color="#ff00ff">1</font>);<br><font color="#000000"></font>      }<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#008b8b">count</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
Are the following two function prototypes same?
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">foobar</font>(<font color="#2e8b57"><b>void</b></font>);<br><font
 color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">foobar</font>();<br></pre>
The following programs should be of some help in finding the answer:
(Compile and run both the programs and see what happens)
<br>
Program 1:
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">foobar1</font>(<font color="#2e8b57"><b>void</b></font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>   <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"In foobar1</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">foobar2</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>   <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"In foobar2</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>  }<br><font
 color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>     <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">ch</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">'a'</font>;<br><font color="#000000"></font>     <font
 color="#008b8b">foobar1</font>();<br><font color="#000000"></font>     <font
 color="#008b8b">foobar2</font>(<font color="#ff00ff">33</font>, <font
 color="#008b8b">ch</font>);<br><font color="#000000"></font>     <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
Program 2:
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">foobar1</font>(<font color="#2e8b57"><b>void</b></font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>   <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"In foobar1</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">foobar2</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>   <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"In foobar2</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>  }<br><font
 color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>     <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">ch</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">'a'</font>;<br><font color="#000000"></font>     <font
 color="#008b8b">foobar1</font>(<font color="#ff00ff">33</font>, <font
 color="#008b8b">ch</font>);<br><font color="#000000"></font>     <font
 color="#008b8b">foobar2</font>();<br><font color="#000000"></font>     <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
What's the output of the following program and why?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>   <font color="#2e8b57"><b>float</b></font> <font
 color="#008b8b">a</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">12.5</font>;<br><font color="#000000"></font>   <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>, <font color="#008b8b">a</font>);<br><font
 color="#000000"></font>   <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>, <font
 color="#a52a2a"><b>*</b></font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#a52a2a"><b>*</b></font>)<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">a</font>);<br><font color="#000000"></font>   <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
The following is a small C program split across files.
What do you expect the output to be, when both of them
compiled together and run?<br>
File1.c
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">arr</font>[<font color="#ff00ff">80</font>];<br></pre>
File2.c
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>extern</b></font> <font
 color="#2e8b57"><b>int</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">arr</font>;<br><font color="#000000"></font>  <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#008b8b">arr</font>[<font color="#ff00ff">1</font>] <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">100</font>;<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
Explain the output of the following C program
(No, the output is not 20).
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font><font color="#a52a2a"><b>=</b></font><font
 color="#ff00ff">1</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>switch</b></font>(<font color="#008b8b">a</font>)<br><font
 color="#000000"></font>      {   <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">b</font><font color="#a52a2a"><b>=</b></font><font
 color="#ff00ff">20</font>;<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>case</b></font> <font color="#ff00ff">1</font>: <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"b is </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">b</font>);<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>default</b></font>:<font
 color="#008b8b">printf</font>(<font color="#ff00ff">"b is </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">b</font>);<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>      }<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
What is the output of the following program?
(Again, it is not 40, (if the size of integer is 4)).
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">SIZE</font><font
 color="#a020f0"> </font><font color="#ff00ff">10</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">size</font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">arr</font>[<font color="#008b8b">SIZE</font>])<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>          <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"size of array is:</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#a52a2a"><b>sizeof</b></font>(<font
 color="#008b8b">arr</font>));<br><font color="#000000"></font>  }<br><font
 color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">arr</font>[<font color="#008b8b">SIZE</font>];<br><font
 color="#000000"></font>          <font color="#008b8b">size</font>(<font
 color="#008b8b">arr</font>);<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
The following is a simple c program, in which there is a function
called Error to display errors. Can you see a potential problem
with the way Error is defined?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdlib.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">Error</font>(<font color="#2e8b57"><b>char</b></font><font
 color="#a52a2a"><b>*</b></font> <font color="#008b8b">s</font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#008b8b">s</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font>;<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">p</font>;<br><font
 color="#000000"></font>      <font color="#008b8b">p</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#008b8b">malloc</font>(<font
 color="#a52a2a"><b>sizeof</b></font>(<font color="#2e8b57"><b>int</b></font>));<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>if</b></font>(<font
 color="#008b8b">p</font> <font color="#a52a2a"><b>==</b></font> <font
 color="#ff00ff">NULL</font>)<br><font color="#000000"></font>      {<br><font
 color="#000000"></font>          <font color="#008b8b">Error</font>(<font
 color="#ff00ff">"Could not allocate the memory</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>          <font color="#008b8b">Error</font>(<font
 color="#ff00ff">"Quitting....</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>          <font
 color="#008b8b">exit</font>(<font color="#ff00ff">1</font>);<br><font
 color="#000000"></font>      }<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>else</b></font>
<font color="#000000"></font>      {<br><font color="#000000"></font>          <font
 color="#0000ff">/*some stuff to use p*/</font>
<font color="#000000"></font>      }<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
What is the differnce between the following function calls to
scanf?(Please notice the space carefully in the second call. Try
removing it and observe the behaviour of the program)
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">c</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">scanf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%c</font><font color="#ff00ff">"</font>,<font
 color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">c</font>);<br><font
 color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%c</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">c</font>);<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#008b8b">scanf</font>(<font
 color="#ff00ff">" </font><font color="#6a5acd">%c</font><font
 color="#ff00ff">"</font>,<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">c</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%c</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">c</font>);<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
What is the potential problem with the following C program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">str</font>[<font color="#ff00ff">80</font>];<br><font
 color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"Enter the string:"</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">scanf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">str</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"You entered:</font><font
 color="#6a5acd">%s\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">str</font>);<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
What is the output of the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">i</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">10</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"i : </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">i</font>);<br><font
 color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"sizeof(i++) is: </font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#a52a2a"><b>sizeof</b></font>(<font color="#008b8b">i</font><font
 color="#a52a2a"><b>++</b></font>));<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"i : </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">i</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
Why does the following program give a warning? (Please remember that
sending a normal pointer to a function requiring const pointer does not
give any warning)
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">foo</font>(<font color="#2e8b57"><b>const</b></font> <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>**</b></font><font
 color="#008b8b">p</font>) { }<br><font color="#000000"></font>  <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>(<font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">argc</font>, <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>**</b></font><font
 color="#008b8b">argv</font>)<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#008b8b">foo</font>(<font
 color="#008b8b">argv</font>);<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
What is the output of the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>          <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">i</font>;<br><font color="#000000"></font>          <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">1</font>,<font color="#ff00ff">2</font>,<font
 color="#ff00ff">3</font>;<br><font color="#000000"></font>          <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"i:</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">i</font>);<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
The following is a piece of code which implements
the reverse Polish Calculator. There is a(are) serious(s) bug in
the code. Find it(them) out!!!
Assume that the function getop returns the appropriate return values
for operands, opcodes, EOF etc..
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdlib.h&gt;</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">MAX</font><font
 color="#a020f0"> </font><font color="#ff00ff">80</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">NUMBER</font><font
 color="#a020f0"> </font><font color="#ff00ff">'0'</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">getop</font>(<font color="#2e8b57"><b>char</b></font>[]);<br><font
 color="#000000"></font>  <font color="#2e8b57"><b>void</b></font> <font
 color="#008b8b">push</font>(<font color="#2e8b57"><b>double</b></font>);<br><font
 color="#000000"></font>  <font color="#2e8b57"><b>double</b></font> <font
 color="#008b8b">pop</font>(<font color="#2e8b57"><b>void</b></font>);<br><font
 color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">type</font>;<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>char</b></font> <font color="#008b8b">s</font>[<font
 color="#008b8b">MAX</font>];<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>while</b></font>((<font
 color="#008b8b">type</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">getop</font>(<font color="#008b8b">s</font>)) <font
 color="#a52a2a"><b>!=</b></font> <font color="#ff00ff">EOF</font>)<br><font
 color="#000000"></font>      {<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>switch</b></font>(<font color="#008b8b">type</font>)<br><font
 color="#000000"></font>          {<br><font color="#000000"></font>              <font
 color="#a52a2a"><b>case</b></font> <font color="#008b8b">NUMBER</font>:<br><font
 color="#000000"></font>                  <font color="#008b8b">push</font>(<font
 color="#008b8b">atof</font>(<font color="#008b8b">s</font>));<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>              <font color="#a52a2a"><b>case</b></font> <font
 color="#ff00ff">'+'</font>:<br><font color="#000000"></font>                  <font
 color="#008b8b">push</font>(<font color="#008b8b">pop</font>() <font
 color="#a52a2a"><b>+</b></font> <font color="#008b8b">pop</font>());<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>              <font color="#a52a2a"><b>case</b></font> <font
 color="#ff00ff">'*'</font>:<br><font color="#000000"></font>                  <font
 color="#008b8b">push</font>(<font color="#008b8b">pop</font>() <font
 color="#a52a2a"><b>*</b></font> <font color="#008b8b">pop</font>());<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>              <font color="#a52a2a"><b>case</b></font> <font
 color="#ff00ff">'-'</font>:<br><font color="#000000"></font>                  <font
 color="#008b8b">push</font>(<font color="#008b8b">pop</font>() <font
 color="#a52a2a"><b>-</b></font> <font color="#008b8b">pop</font>());<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>              <font color="#a52a2a"><b>case</b></font> <font
 color="#ff00ff">'/'</font>:<br><font color="#000000"></font>                  <font
 color="#008b8b">push</font>(<font color="#008b8b">pop</font>() <font
 color="#a52a2a"><b>/</b></font> <font color="#008b8b">pop</font>());<br><font
 color="#000000"></font>                  <font color="#a52a2a"><b>break</b></font>;<br><font
 color="#000000"></font>              <font color="#0000ff">/*   ... </font>
<font color="#000000"></font>  <font color="#0000ff">             *   ...    </font>
<font color="#000000"></font>  <font color="#0000ff">             *   ... </font>
<font color="#000000"></font>  <font color="#0000ff">             */</font>
<font color="#000000"></font>          }<br><font color="#000000"></font>      }<br><font
 color="#000000"></font>  }<br></pre>
<hr>
The following is a simple program which implements a minimal
version of <b>banner</b> command available on most *nix systems.
Find out the logic used in the program.
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#ff00ff">&lt;ctype.h&gt;</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">t</font>[]<font color="#a52a2a"><b>=</b></font>{<br><font
 color="#000000"></font>      <font color="#a020f0">0</font>,<font
 color="#a020f0">0</font>,<font color="#a020f0">0</font>,<font
 color="#a020f0">0</font>,<font color="#a020f0">0</font>,<font
 color="#a020f0">0</font>,<font color="#ff00ff">12</font>,<font
 color="#ff00ff">18</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">63</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">62</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">62</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">62</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">33</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">62</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">62</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">63</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">62</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">63</font>,<font
 color="#ff00ff">63</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">62</font>,<font color="#ff00ff">32</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">30</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">39</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">63</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">1</font>,<font
 color="#ff00ff">1</font>,<font color="#ff00ff">1</font>,<font
 color="#ff00ff">1</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">34</font>,<font color="#ff00ff">60</font>,<font
 color="#ff00ff">36</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">34</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">63</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">51</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">45</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">49</font>,<font color="#ff00ff">41</font>,<font
 color="#ff00ff">37</font>,<font color="#ff00ff">35</font>,<font
 color="#ff00ff">33</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">30</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">30</font>,<font
 color="#ff00ff">62</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">62</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">32</font>,<font
 color="#ff00ff">32</font>,<font color="#ff00ff">30</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">37</font>,<font color="#ff00ff">34</font>,<font
 color="#ff00ff">29</font>,<font color="#ff00ff">62</font>,<font
 color="#ff00ff">33</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">33</font>,<font color="#ff00ff">62</font>,<font
 color="#ff00ff">34</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">32</font>,<font
 color="#ff00ff">30</font>,<font color="#ff00ff">1</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">30</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">31</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">33</font>,<font color="#ff00ff">30</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">18</font>,<font color="#ff00ff">12</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">33</font>,<font
 color="#ff00ff">45</font>,<font color="#ff00ff">51</font>,<font
 color="#ff00ff">33</font>,<font color="#ff00ff">33</font>,<font
 color="#ff00ff">18</font>,<font color="#ff00ff">12</font>,<font
 color="#ff00ff">12</font>,<font color="#ff00ff">18</font>,<font
 color="#ff00ff">33</font>,<br><font color="#000000"></font>      <font
 color="#ff00ff">17</font>,<font color="#ff00ff">10</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">4</font>,<font
 color="#ff00ff">63</font>,<font color="#ff00ff">2</font>,<font
 color="#ff00ff">4</font>,<font color="#ff00ff">8</font>,<br><font
 color="#000000"></font>      <font color="#ff00ff">16</font>,<font
 color="#ff00ff">63</font>
<font color="#000000"></font>      };<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">argc</font>,<font color="#2e8b57"><b>char</b></font><font
 color="#a52a2a"><b>**</b></font> <font color="#008b8b">argv</font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">r</font>,<font color="#008b8b">pr</font>;<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>for</b></font>(<font
 color="#008b8b">r</font><font color="#a52a2a"><b>=</b></font><font
 color="#a020f0">0</font>;<font color="#008b8b">r</font><font
 color="#a52a2a"><b>&lt;</b></font><font color="#ff00ff">6</font>;<font
 color="#a52a2a"><b>++</b></font><font color="#008b8b">r</font>)<br><font
 color="#000000"></font>          {<br><font color="#000000"></font>          <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">p</font><font color="#a52a2a"><b>=</b></font><font
 color="#008b8b">argv</font>[<font color="#ff00ff">1</font>];<br><font
 color="#000000"></font>
<font color="#000000"></font>          <font color="#a52a2a"><b>while</b></font>(<font
 color="#008b8b">pr</font><font color="#a52a2a"><b>&amp;&amp;</b></font><font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">p</font>)<br><font
 color="#000000"></font>              {<br><font color="#000000"></font>              <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">o</font><font
 color="#a52a2a"><b>=</b></font>(<font color="#008b8b">toupper</font>(<font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">p</font><font
 color="#a52a2a"><b>++</b></font>)<font color="#a52a2a"><b>-</b></font><font
 color="#ff00ff">'A'</font>)<font color="#a52a2a"><b>*</b></font><font
 color="#ff00ff">6</font><font color="#a52a2a"><b>+</b></font><font
 color="#ff00ff">6</font><font color="#a52a2a"><b>+</b></font><font
 color="#008b8b">r</font>;<br><font color="#000000"></font>              <font
 color="#008b8b">o</font><font color="#a52a2a"><b>=</b></font>(<font
 color="#008b8b">o</font><font color="#a52a2a"><b>&lt;</b></font><font
 color="#a020f0">0</font><font color="#a52a2a"><b>||</b></font><font
 color="#008b8b">o</font><font color="#a52a2a"><b>&gt;=</b></font><font
 color="#a52a2a"><b>sizeof</b></font>(<font color="#008b8b">t</font>))<font
 color="#a52a2a"><b>?</b></font><font color="#a020f0">0</font><font
 color="#a52a2a"><b>:</b></font><font color="#008b8b">o</font>;<br><font
 color="#000000"></font>              <font color="#a52a2a"><b>for</b></font>(<font
 color="#008b8b">pr</font><font color="#a52a2a"><b>=</b></font><font
 color="#ff00ff">5</font>;<font color="#008b8b">pr</font><font
 color="#a52a2a"><b>&gt;=</b></font><font color="#a52a2a"><b>-</b></font><font
 color="#ff00ff">1</font>;<font color="#a52a2a"><b>--</b></font><font
 color="#008b8b">pr</font>)<br><font color="#000000"></font>                  {<br><font
 color="#000000"></font>                  <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%c</font><font
 color="#ff00ff">"</font>,( ( (<font color="#008b8b">pr</font><font
 color="#a52a2a"><b>&gt;=</b></font><font color="#a020f0">0</font>) <font
 color="#a52a2a"><b>&amp;&amp;</b></font> (<font color="#008b8b">t</font>[<font
 color="#008b8b">o</font>]<font color="#a52a2a"><b>&amp;</b></font>(<font
 color="#ff00ff">1</font><font color="#a52a2a"><b>&lt;&lt;</b></font><font
 color="#008b8b">pr</font>)))<font color="#a52a2a"><b>?</b></font><font
 color="#ff00ff">'#'</font><font color="#a52a2a"><b>:</b></font><font
 color="#ff00ff">' '</font>));<br><font color="#000000"></font>
<font color="#000000"></font>                  }<br><font
 color="#000000"></font>              }<br><font color="#000000"></font>          <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>          }<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
</pre>
<hr>What is the output of the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdlib.h&gt;</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">SIZEOF</font><font
 color="#a020f0">(</font><font color="#008b8b">arr</font><font
 color="#a020f0">) (</font><font color="#a52a2a"><b>sizeof</b></font><font
 color="#a020f0">(</font><font color="#008b8b">arr</font><font
 color="#a020f0">)</font><font color="#a52a2a"><b>/</b></font><font
 color="#a52a2a"><b>sizeof</b></font><font color="#a020f0">(</font><font
 color="#008b8b">arr</font><font color="#a020f0">[</font><font
 color="#a020f0">0</font><font color="#a020f0">]))</font>
<font color="#000000"></font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">PrintInt</font><font
 color="#a020f0">(</font><font color="#008b8b">expr</font><font
 color="#a020f0">) </font><font color="#008b8b">printf</font><font
 color="#a020f0">(</font><font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff">:</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font><font color="#a020f0">,#</font><font
 color="#008b8b">expr</font><font color="#a020f0">,(</font><font
 color="#008b8b">expr</font><font color="#a020f0">))</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#0000ff">/* The powers of 10 */</font>
<font color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">pot</font>[] <font color="#a52a2a"><b>=</b></font> {<br><font
 color="#000000"></font>          <font color="#a020f0">000</font><font
 color="#ff00ff">1</font>,<br><font color="#000000"></font>          <font
 color="#a020f0">00</font><font color="#ff00ff">1</font><font
 color="#a020f0">0</font>,<br><font color="#000000"></font>          <font
 color="#a020f0">0</font><font color="#ff00ff">1</font><font
 color="#a020f0">00</font>,<br><font color="#000000"></font>          <font
 color="#ff00ff">1000</font>
<font color="#000000"></font>      };<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">i</font>;<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>for</b></font>(<font
 color="#008b8b">i</font><font color="#a52a2a"><b>=</b></font><font
 color="#a020f0">0</font>;<font color="#008b8b">i</font><font
 color="#a52a2a"><b>&lt;</b></font><font color="#a020f0">SIZEOF</font>(<font
 color="#008b8b">pot</font>);<font color="#008b8b">i</font><font
 color="#a52a2a"><b>++</b></font>)<br><font color="#000000"></font>          <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">pot</font>[<font
 color="#008b8b">i</font>]);<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
The following is the implementation of the <i>Euclid's algorithm</i>
for finding the <b>G.C.D(Greatest Common divisor)
</b>of two integers.
Explain the logic for the below implementation and think
of any possible improvements on the current implementation.
<br>
BTW, what does <b>scanf</b> function return?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">gcd</font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">u</font>,<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">v</font>)<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">t</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>while</b></font>(<font color="#008b8b">v</font> <font
 color="#a52a2a"><b>&gt;</b></font> <font color="#a020f0">0</font>)<br><font
 color="#000000"></font>      {<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>if</b></font>(<font color="#008b8b">u</font> <font
 color="#a52a2a"><b>&gt;</b></font> <font color="#008b8b">v</font>)<br><font
 color="#000000"></font>          {<br><font color="#000000"></font>              <font
 color="#008b8b">t</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">u</font>;<br><font color="#000000"></font>              <font
 color="#008b8b">u</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">v</font>;<br><font color="#000000"></font>              <font
 color="#008b8b">v</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">t</font>;<br><font color="#000000"></font>          }<br><font
 color="#000000"></font>          <font color="#008b8b">v</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#008b8b">v</font><font
 color="#a52a2a"><b>-</b></font><font color="#008b8b">u</font>;<br><font
 color="#000000"></font>      }<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#008b8b">u</font>;<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">x</font>,<font color="#008b8b">y</font>;<br><font
 color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"Enter x y to find their gcd:"</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>while</b></font>(<font
 color="#008b8b">scanf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%d%d</font><font color="#ff00ff">"</font>,<font
 color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">x</font>, <font
 color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">y</font>) <font
 color="#a52a2a"><b>!=</b></font> <font color="#ff00ff">EOF</font>)<br><font
 color="#000000"></font>      {<br><font color="#000000"></font>          <font
 color="#a52a2a"><b>if</b></font>(<font color="#008b8b">x</font> <font
 color="#a52a2a"><b>&gt;</b></font><font color="#a020f0">0</font> <font
 color="#a52a2a"><b>&amp;&amp;</b></font> <font color="#008b8b">y</font><font
 color="#a52a2a"><b>&gt;</b></font><font color="#a020f0">0</font>)<br><font
 color="#000000"></font>              <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#ff00ff"> </font><font color="#6a5acd">%d</font><font
 color="#ff00ff"> </font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">x</font>,<font color="#008b8b">y</font>,<font
 color="#008b8b">gcd</font>(<font color="#008b8b">x</font>,<font
 color="#008b8b">y</font>));<br><font color="#000000"></font>                  <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"Enter x y to find their gcd:"</font>);<br><font
 color="#000000"></font>      }<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br><font
 color="#000000"></font>
</pre>
Also implement a C function similar to the above to
find the <b>GCD of 4 integers.</b>
<hr>What's the output of the following program. (No, it's not 10!!!)
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">PrintInt</font><font
 color="#a020f0">(</font><font color="#008b8b">expr</font><font
 color="#a020f0">) </font><font color="#008b8b">printf</font><font
 color="#a020f0">(</font><font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff"> : </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font><font color="#a020f0">,#</font><font
 color="#008b8b">expr</font><font color="#a020f0">,(</font><font
 color="#008b8b">expr</font><font color="#a020f0">))</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">y</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">100</font>;<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>int</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">p</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">p</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">malloc</font>(<font color="#a52a2a"><b>sizeof</b></font>(<font
 color="#2e8b57"><b>int</b></font>));<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">p</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">10</font>;<br><font
 color="#000000"></font>      <font color="#008b8b">y</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#008b8b">y/*p;</font><font
 color="#0000ff"> /*dividing y by *p */</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">y</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>The following is a simple C program to read a date
and print the date. Run it and explain the behaviour
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">day</font>,<font color="#008b8b">month</font>,<font
 color="#008b8b">year</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"Enter the date (dd-mm-yyyy) format including -'s:"</font>);<br><font
 color="#000000"></font>      <font color="#008b8b">scanf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#ff00ff">-</font><font color="#6a5acd">%d</font><font
 color="#ff00ff">-</font><font color="#6a5acd">%d</font><font
 color="#ff00ff">"</font>,<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">day</font>,<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">month</font>,<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">year</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"The date you have entered is </font><font
 color="#6a5acd">%d</font><font color="#ff00ff">-</font><font
 color="#6a5acd">%d</font><font color="#ff00ff">-</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">day</font>,<font
 color="#008b8b">month</font>,<font color="#008b8b">year</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
The following is a simple C program to read and
print an integer. But it is not working properly.
What is(are) the mistake(s)?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">n</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"Enter a number:</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>);<br><font
 color="#000000"></font>      <font color="#008b8b">scanf</font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">n</font>);<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"You entered </font><font color="#6a5acd">%d</font><font
 color="#ff00ff"> </font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">n</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
The following is a simple C program which tries to multiply
an integer by 5 using the bitwise operations. But it doesn't do so.
Explain the reason for the wrong behaviour of the program.
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">PrintInt</font><font
 color="#a020f0">(</font><font color="#008b8b">expr</font><font
 color="#a020f0">) </font><font color="#008b8b">printf</font><font
 color="#a020f0">(</font><font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff"> : </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font><font color="#a020f0">,#</font><font
 color="#008b8b">expr</font><font color="#a020f0">,(</font><font
 color="#008b8b">expr</font><font color="#a020f0">))</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">FiveTimes</font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font>)<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">t</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">t</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">a</font><font color="#a52a2a"><b>&lt;&lt;</b></font><font
 color="#ff00ff">2</font> <font color="#a52a2a"><b>+</b></font> <font
 color="#008b8b">a</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#008b8b">t</font>;<br><font
 color="#000000"></font>  }<br><font color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">1</font>, <font color="#008b8b">b</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">2</font>,<font
 color="#008b8b">c</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">3</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">FiveTimes</font>(<font
 color="#008b8b">a</font>));<br><font color="#000000"></font>      <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">FiveTimes</font>(<font
 color="#008b8b">b</font>));<br><font color="#000000"></font>      <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">FiveTimes</font>(<font
 color="#008b8b">c</font>));<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
Is the following a valid C program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">PrintInt</font><font
 color="#a020f0">(</font><font color="#008b8b">expr</font><font
 color="#a020f0">) </font><font color="#008b8b">printf</font><font
 color="#a020f0">(</font><font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff"> : </font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font><font color="#a020f0">,#</font><font
 color="#008b8b">expr</font><font color="#a020f0">,(</font><font
 color="#008b8b">expr</font><font color="#a020f0">))</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">max</font>(<font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">x</font>, <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">y</font>)<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      (<font color="#008b8b">x</font> <font
 color="#a52a2a"><b>&gt;</b></font> <font color="#008b8b">y</font>) <font
 color="#a52a2a"><b>? </b></font><font color="#a52a2a"><b>return</b></font><font
 color="#a52a2a"><b> </b></font><font color="#008b8b">x</font><font
 color="#a52a2a"><b> :</b></font> <font color="#a52a2a"><b>return</b></font> <font
 color="#008b8b">y</font>;<br><font color="#000000"></font>  }<br><font
 color="#000000"></font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">10</font>, <font color="#008b8b">b</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">20</font>;<br><font
 color="#000000"></font>      <font color="#008b8b">PrintInt</font>(<font
 color="#008b8b">a</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">PrintInt</font>(<font color="#008b8b">b</font>);<br><font
 color="#000000"></font>      <font color="#008b8b">PrintInt</font>(<font
 color="#008b8b">max</font>(<font color="#008b8b">a</font>,<font
 color="#008b8b">b</font>));<br><font color="#000000"></font>  }<br></pre>
<hr>The following is a piece of C code, whose intention
was to print a minus sign 20 times. But you can notice
that, it doesn't work.
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">i</font>;<br><font color="#000000"></font>      <font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">n</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">20</font>;<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>for</b></font>( <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#a020f0">0</font>; <font color="#008b8b">i</font> <font
 color="#a52a2a"><b>&lt;</b></font> <font color="#008b8b">n</font>; <font
 color="#008b8b">i</font><font color="#a52a2a"><b>--</b></font> )<br><font
 color="#000000"></font>          <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"-"</font>);<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
Well fixing the above code is straight-forward.
To make the problem interesting, you have to fix
the above code, by changing exactly <b>one</b> character.
There are three known solutions. See if you can get
all those three.
<hr>What's the mistake in the following code?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font><font
 color="#a52a2a"><b>*</b></font> <font color="#008b8b">ptr1</font>,<font
 color="#008b8b">ptr2</font>;<br><font color="#000000"></font>      <font
 color="#008b8b">ptr1</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">malloc</font>(<font color="#a52a2a"><b>sizeof</b></font>(<font
 color="#2e8b57"><b>int</b></font>));<br><font color="#000000"></font>      <font
 color="#008b8b">ptr2</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">ptr1</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">ptr2</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">10</font>;<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
What is the output of the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">cnt</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">5</font>, <font color="#008b8b">a</font>;<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>do</b></font> {<br><font
 color="#000000"></font>          <font color="#008b8b">a</font> <font
 color="#a52a2a"><b>/=</b></font> <font color="#008b8b">cnt</font>;<br><font
 color="#000000"></font>      } <font color="#a52a2a"><b>while</b></font> (<font
 color="#008b8b">cnt</font> <font color="#a52a2a"><b>--</b></font>);<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#008b8b">printf </font>(<font
 color="#ff00ff">"</font><font color="#6a5acd">%d</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>, <font
 color="#008b8b">a</font>);<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
What is the output of the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>=</b></font> <font
 color="#ff00ff">6</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>if</b></font>( ((<font color="#a52a2a"><b>++</b></font><font
 color="#008b8b">i</font> <font color="#a52a2a"><b>&lt;</b></font> <font
 color="#ff00ff">7</font>) <font color="#a52a2a"><b>&amp;&amp;</b></font> ( <font
 color="#008b8b">i</font><font color="#a52a2a"><b>++/</b></font><font
 color="#ff00ff">6</font>)) <font color="#a52a2a"><b>||</b></font> (<font
 color="#a52a2a"><b>++</b></font><font color="#008b8b">i</font> <font
 color="#a52a2a"><b>&lt;=</b></font> <font color="#ff00ff">9</font>))<br><font
 color="#000000"></font>          ;<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">i</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
What is the bug in the following program?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdlib.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">SIZE</font><font
 color="#a020f0"> </font><font color="#ff00ff">15</font><font
 color="#a020f0"> </font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>int</b></font> <font
 color="#a52a2a"><b>*</b></font><font color="#008b8b">a</font>, <font
 color="#008b8b">i</font>;<br><font color="#000000"></font>
<font color="#000000"></font>      <font color="#008b8b">a</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#008b8b">malloc</font>(<font
 color="#008b8b">SIZE</font><font color="#a52a2a"><b>*</b></font><font
 color="#a52a2a"><b>sizeof</b></font>(<font color="#2e8b57"><b>int</b></font>));<br><font
 color="#000000"></font>
<font color="#000000"></font>      <font color="#a52a2a"><b>for</b></font> (<font
 color="#008b8b">i</font><font color="#a52a2a"><b>=</b></font><font
 color="#a020f0">0</font>; <font color="#008b8b">i</font><font
 color="#a52a2a"><b>&lt;</b></font><font color="#008b8b">SIZE</font>; <font
 color="#008b8b">i</font><font color="#a52a2a"><b>++</b></font>)<br><font
 color="#000000"></font>          <font color="#a52a2a"><b>*</b></font>(<font
 color="#008b8b">a</font> <font color="#a52a2a"><b>+</b></font> <font
 color="#008b8b">i</font>) <font color="#a52a2a"><b>=</b></font> <font
 color="#008b8b">i</font> <font color="#a52a2a"><b>*</b></font> <font
 color="#008b8b">i</font>;<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>for</b></font> (<font color="#008b8b">i</font><font
 color="#a52a2a"><b>=</b></font><font color="#a020f0">0</font>; <font
 color="#008b8b">i</font><font color="#a52a2a"><b>&lt;</b></font><font
 color="#008b8b">SIZE</font>; <font color="#008b8b">i</font><font
 color="#a52a2a"><b>++</b></font>)<br><font color="#000000"></font>          <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>, <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">a</font><font color="#a52a2a"><b>++</b></font>);<br><font
 color="#000000"></font>      <font color="#008b8b">free</font>(<font
 color="#008b8b">a</font>);<br><font color="#000000"></font>      <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>
Is the following a valid C program? If so, what is the output
of it?
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>    <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">a</font><font color="#a52a2a"><b>=</b></font><font
 color="#ff00ff">3</font>, <font color="#008b8b">b</font> <font
 color="#a52a2a"><b>=</b></font> <font color="#ff00ff">5</font>;<br><font
 color="#000000"></font>
<font color="#000000"></font>    <font color="#008b8b">printf</font>(<font
 color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">a</font>[<font
 color="#ff00ff">"Ya!Hello! how is this? </font><font color="#6a5acd">%s</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>], <font
 color="#a52a2a"><b>&amp;</b></font><font color="#008b8b">b</font>[<font
 color="#ff00ff">"junk/super"</font>]);<br><font color="#000000"></font>    <font
 color="#008b8b">printf</font>(<font color="#a52a2a"><b>&amp;</b></font><font
 color="#008b8b">a</font>[<font color="#ff00ff">"WHAT</font><font
 color="#6a5acd">%c%c%c</font><font color="#ff00ff">  </font><font
 color="#6a5acd">%c%c</font><font color="#ff00ff">  </font><font
 color="#6a5acd">%c</font><font color="#ff00ff"> !</font><font
 color="#6a5acd">\n</font><font color="#ff00ff">"</font>], <font
 color="#ff00ff">1</font>[<font color="#ff00ff">"this"</font>],<br><font
 color="#000000"></font>       <font color="#ff00ff">2</font>[<font
 color="#ff00ff">"beauty"</font>],<font color="#a020f0">0</font>[<font
 color="#ff00ff">"tool"</font>],<font color="#a020f0">0</font>[<font
 color="#ff00ff">"is"</font>],<font color="#ff00ff">3</font>[<font
 color="#ff00ff">"sensitive"</font>],<font color="#ff00ff">4</font>[<font
 color="#ff00ff">"CCCCCC"</font>]);<br><font color="#000000"></font>    <font
 color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;<br><font
 color="#000000"></font>  }<br></pre>
<hr>What is the output of the following, if the input provided is:<br>
<b>Life is beautiful</b>
<pre><font color="#000000"></font>  <font color="#a020f0">#include</font><font
 color="#a020f0"> </font><font color="#ff00ff">&lt;stdio.h&gt;</font>
<font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">main</font>()<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">dummy</font>[<font color="#ff00ff">80</font>];<br><font
 color="#000000"></font>      <font color="#008b8b">printf</font>(<font
 color="#ff00ff">"Enter a string:</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">scanf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%[^a]</font><font color="#ff00ff">"</font>,<font
 color="#008b8b">dummy</font>);<br><font color="#000000"></font>      <font
 color="#008b8b">printf</font>(<font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font>,<font color="#008b8b">dummy</font>);<br><font
 color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
<i> <b>Note</b> : This question has more to do with Linker than C language</i>
<br>
We have three files a.c, b.c and main.c respectively as follows:
<br>
a.c<br>
---
	<pre>
<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">a</font>;
</pre>

b.c<br>
---
<pre>
<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">a</font> <font color="#a52a2a"><b>=</b></font> <font color="#ff00ff">10</font>;
</pre>

main.c<br>
------
<pre>
<font color="#2e8b57"><b>extern</b></font> <font color="#2e8b57"><b>int</b></font> <font color="#008b8b">a</font>;
<font color="#2e8b57"><b>int</b></font> <font color="#008b8b">main</font>()
{
        <font color="#008b8b">printf</font>(<font color="#ff00ff">&quot;a = </font><font color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font color="#ff00ff">&quot;</font>,<font color="#008b8b">a</font>);
        <font color="#a52a2a"><b>return</b></font> <font color="#a020f0">0</font>;
}
</pre>

Let's see what happens, when the files are compiled together:
<pre>
bash$ gcc a.c b.c main.c
bash$ ./a.out
a = 10
</pre>
Hmm!! no compilation/linker error!!! Why is it so??

<hr>
The following is the <b>offset</b> macros which is used many a times.
Figure out what is it trying to do and what is the advantage of
using it.
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">offsetof</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">,</font><font color="#008b8b">b</font><font
 color="#a020f0">) ((</font><font color="#2e8b57"><b>int</b></font><font
 color="#a020f0">)(</font><font color="#a52a2a"><b>&amp;</b></font><font
 color="#a020f0">(((</font><font color="#008b8b">a</font><font
 color="#a52a2a"><b>*</b></font><font color="#a020f0">)(</font><font
 color="#a020f0">0</font><font color="#a020f0">))</font><font
 color="#a52a2a"><b>-&gt;</b></font><font color="#008b8b">b</font><font
 color="#a020f0">)))</font>
</pre>
<hr>
The following is the macro implementation of the famous, <i>Triple xor
swap</i>.
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">SWAP</font><font
 color="#a020f0">(</font><font color="#008b8b">a</font><font
 color="#a020f0">,</font><font color="#008b8b">b</font><font
 color="#a020f0">) ((</font><font color="#008b8b">a</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>^=</b></font><font
 color="#a020f0"> (</font><font color="#008b8b">b</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>^=</b></font><font
 color="#a020f0"> (</font><font color="#008b8b">a</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>^=</b></font><font
 color="#a020f0"> (</font><font color="#008b8b">b</font><font
 color="#a020f0">))</font>
</pre>
What are the potential problems with the above macro?
<hr>What is the use of the following macro?
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">DPRINTF</font><font
 color="#a020f0">(</font><font color="#008b8b">x</font><font
 color="#a020f0">) </font><font color="#008b8b">printf</font><font
 color="#a020f0">(</font><font color="#ff00ff">"</font><font
 color="#6a5acd">%s</font><font color="#ff00ff">:</font><font
 color="#6a5acd">%d</font><font color="#6a5acd">\n</font><font
 color="#ff00ff">"</font><font color="#a020f0">,#</font><font
 color="#008b8b">x</font><font color="#a020f0">,</font><font
 color="#008b8b">x</font><font color="#a020f0">)</font>
</pre>
<hr>
Let's say you were asked to code a function IAddOverFlow which takes
three
parameters, pointer to an integer where the result is to be stored, and
the two integers which needs to be added. It returns 0 if there is
an overflow and 1 otherwise:
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">IAddOverFlow</font>(<font color="#2e8b57"><b>int</b></font><font
 color="#a52a2a"><b>*</b></font> <font color="#008b8b">result</font>,<font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">a</font>,<font
 color="#2e8b57"><b>int</b></font> <font color="#008b8b">b</font>)<br><font
 color="#000000"></font>  {<br><font color="#000000"></font>      <font
 color="#0000ff">/* ... */</font>
<font color="#000000"></font>  }<br></pre>
So, how do you code the above function?
(To put in a nutshell, what is the logic you use for overflow
detection?)
<hr>What does the following macro do?
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">ROUNDUP</font><font
 color="#a020f0">(</font><font color="#008b8b">x</font><font
 color="#a020f0">,</font><font color="#008b8b">n</font><font
 color="#a020f0">) ((</font><font color="#008b8b">x</font><font
 color="#a52a2a"><b>+</b></font><font color="#008b8b">n</font><font
 color="#a52a2a"><b>-</b></font><font color="#ff00ff">1</font><font
 color="#a020f0">)</font><font color="#a52a2a"><b>&amp;</b></font><font
 color="#a020f0">(</font><font color="#a52a2a"><b>~</b></font><font
 color="#a020f0">(</font><font color="#008b8b">n</font><font
 color="#a52a2a"><b>-</b></font><font color="#ff00ff">1</font><font
 color="#a020f0">)))</font>
</pre>
<hr>
Most of the C programming books, give the following example for
the definition of macros.
<pre><font color="#000000"></font>  <font color="#a020f0">#define</font><font
 color="#a020f0"> </font><font color="#008b8b">isupper</font><font
 color="#a020f0">(</font><font color="#008b8b">c</font><font
 color="#a020f0">) (((</font><font color="#008b8b">c</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>&gt;=</b></font><font
 color="#a020f0"> </font><font color="#ff00ff">'A'</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>&amp;&amp;</b></font><font
 color="#a020f0"> ((</font><font color="#008b8b">c</font><font
 color="#a020f0">) </font><font color="#a52a2a"><b>&lt;=</b></font><font
 color="#a020f0"> </font><font color="#ff00ff">'Z'</font><font
 color="#a020f0">))</font>
</pre>
But there would be a serious problem with the above definition of
macro, if it is used as follows (what is the problem??)
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>char</b></font> <font
 color="#008b8b">c</font>;<br><font color="#000000"></font>  <font
 color="#0000ff">/* ... */</font>
<font color="#000000"></font>  <font color="#a52a2a"><b>if</b></font>(<font
 color="#008b8b">isupper</font>(<font color="#008b8b">c</font><font
 color="#a52a2a"><b>++</b></font>))<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#0000ff">/* ... */</font>
<font color="#000000"></font>  }<br></pre>
But most of the libraries implement the <i>isupper</i> (declared in
ctypes.h) as a macro (without any side effects). Find out how <i>isupper()</i>
is implemented on your system.
<hr>I hope you know that <i>ellipsis (...) </i> is used to specify
variable number of arguments to a function.
(What is the function prototype declaration for <b>printf</b>?)
What is wrong with the following delcaration?
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>int</b></font> <font
 color="#008b8b">VarArguments</font>(...)<br><font color="#000000"></font>  {<br><font
 color="#000000"></font>      <font color="#0000ff">/*....*/</font>
<font color="#000000"></font>      <font color="#a52a2a"><b>return</b></font> <font
 color="#a020f0">0</font>;<br><font color="#000000"></font>  }<br></pre>
<hr>
Write a C program to find the
smallest of three integers, <b>without using any of the
	comparision operators</b>.
<hr>What does the format specifier <b>%n</b> of <b>printf</b>
function do?
<hr>
Write a C function which does the addition of two integers
without using the '+' operator. You can use only the bitwise
operators.(Remember the good old method of implementing
the full-adder circuit using the or, and, xor gates....)
<hr>How do you print <b>I can print %</b> using the <b>printf</b>
function?
(Remember <b>%</b> is used as a format specifier!!!)
<hr>
What's the difference between the following two C statements?
<pre><font color="#000000"></font>  <font color="#2e8b57"><b>const</b></font> <font
 color="#2e8b57"><b>char</b></font> <font color="#a52a2a"><b>*</b></font><font
 color="#008b8b">p</font>;<br><font color="#000000"></font>  <font
 color="#2e8b57"><b>char</b></font><font color="#a52a2a"><b>*</b></font> <font
 color="#2e8b57"><b>const</b></font> <font color="#008b8b">p</font>;<br></pre>
<hr>
What is the difference between <b>memcpy</b> and <b>memmove</b>?
<hr>What is the format specifiers for <b>printf</b> to print double
and float values?
<hr>
Write a small C program to determine whether a
machine's type is little-endian or big-endian.
<hr>
Write a C program which prints <b>Hello World!</b> without using
a semicolon!!!


<p>
<a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">
<img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-sa/3.0/88x31.png" /></a>
This <span xmlns:dct="http://purl.org/dc/terms/" href="http://purl.org/dc/dcmitype/Text" rel="dct:type">work</span> 
by <a xmlns:cc="http://creativecommons.org/ns#" href="http://www.gowrikumar.com" property="cc:attributionName" 
rel="cc:attributionURL">Gowri Kumar Chandramouli</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/3.0/">
Creative Commons Attribution-ShareAlike 3.0 Unported License</a>.

<script src="http://www.google-analytics.com/urchin.js" type="text/javascript">
</script>
<script type="text/javascript">
_uacct = "UA-256880-1";
urchinTracker();
</script>

	</body>
</HTML>