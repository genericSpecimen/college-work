package tags;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class SubstringTag extends SimpleTagSupport {
    private String input, start, end;
    private int a, b;

    public void setInput(String input) {
        this.input = input;
    }
    public void setStart(String start) throws IOException, NumberFormatException {
        this.start = start;
        a = Integer.parseInt(start);
    }
    public void setEnd(String end) throws IOException, NumberFormatException {
        this.end = end;
        b = Integer.parseInt(end);
    }

    public void doTag() throws IOException {
        JspWriter out = getJspContext().getOut();
        out.println(input.substring(a,b));
    }
}
