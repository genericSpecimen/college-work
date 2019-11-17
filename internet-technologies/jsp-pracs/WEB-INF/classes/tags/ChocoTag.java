package tags;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

public class ChocoTag extends SimpleTagSupport {
    private String texture;
    public void setTexture(String texture) {
        this.texture = texture;
    }
    public void doTag() throws IOException {
        JspWriter out = getJspContext().getOut();
        if(texture.equalsIgnoreCase("chewy")) {
            out.println("FiveStar, BarOne");
        } else if(texture.equalsIgnoreCase("crunchy")) {
            out.println("Munch, KitKat");
        }
    }
}

