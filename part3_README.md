## Platformer - Part 3

<img align="right" width="100px" src="./media/miyamoto.JPG" style="float:left;">

Ship it! Shigeru Miyamoto is confident after your success with breakout that you understand how to test and deploy software. He thinks the special mechanic you have implemented may even top that of his Mario creation! However, what makes Shigeru Miyamoto a great developer is his rigor and discipline. With that--he would like you to perform a postmortem for part 3 of this journey and market our final product. 

## Step 1 - Documentation
While Miyamoto has given the greenlight, he wants to ensure the code is wrapped up nicely so it can be reused. Miyamoto has suggested using 'Doxygen' <a href="http://www.doxygen.nl/">(Doxygen webpage)</a> or [Doxypress](https://www.copperspice.com/documentation-doxypress.html) to document the source code and automatically generate .html pages. Your documentation should cover your classes and functions.

An example of a well documented probjects can be found here: 

- https://www.ogre3d.org/docs/api/1.9/
- http://www.horde3d.org/docs/html/_api.html

### Doxygen style comments

Some examples of documentation are listed here: http://www.doxygen.nl/manual/docblocks.html 

Comments within code are in the style of:

```cpp
/*!
 * ... text ...
 */

/*!
 ... text ...
*/

//!
//!... text ...
//!

/*! \brief Brief description.
 *         Brief description continued.
 *
 *  Detailed description starts here.
 */

```
**Note**: A helpful tool to use may be: [Doxywizard](http://www.doxygen.nl/manual/doxywizard_usage.html)

## Step 2 - Build (binary file)
You need to have a compiled binary of your game for your operating system (Either Windows, Mac, or Linux). You can assume a target audience of either a 64-bit Mac, Ubuntu Linux, or a Windows 10 machine. There should additionally be instructions about how to compile your code from source. The compilation should be trivial (running `python build.py` for example, or listing a series of 'apt-get install' in a single command or a script you have built. **Make it trivial** so customers/course staff do not get frustrated :) ).

## Step 3 - Post mortem
A post mortem in games is a look back at what could be improved. Write a brief (2-3 paragraphs) on what could be improved if you had an additional 8 weeks to work on this project. Where would you allocate time, what tools would you build, would you use any different tools, etc.

*Edit here a draft of your post mortem here if you like--the final copy goes in your 1-page .html website. Think of this section as a good 'reflection' for what you can improve on your next project you complete.*

## Step 4 - Website

Your documentation, a link to your binary, and your post mortem should be put together on a 1-page .html page. 

Additionally, provide a 1 minute video trailer followed by at least 3 screenshots of your game (order matters, video first, then screenshots below). This website will be the first place I look to grab your project files and binaries. 

*Please provide a link to your website here, or otherwise on the front page of your README.md*

**Note**: I think it is incredibly important to build a portfolio of your game development works! You can re-use this template for your next project, and potentially other personal projects.


### Part 3 - Rubric (4% of overall grade)

<table>
  <tbody>
    <tr>
      <th>Points</th>
      <th align="center">Description</th>
    </tr>
    <tr>
      <td>25% (Documentation)</td>
      <td align="left">Did you generate something like "http://www.horde3d.org/docs/html/_api.html"?</td>
    </tr>    
    <tr>
      <td>25% (Build)</td>
      <td align="left">Does the build work when I download your repo and run the game?</td>
    </tr>
    <tr>
      <td>25% (Post mortem)</td>
      <td align="left">Did you learn anything and provide a brief and well-thought out reflection of these learnings?</td>
    </tr>
    <tr>
      <td>25% (Website)</td>
      <td align="left">Do you have a webpage that presents your project in a positive way with the above materials.</td>
    </tr>
  </tbody>
</table>


