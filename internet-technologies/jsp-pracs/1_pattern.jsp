<%@ page contentType="text/html" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
    <body>
        <form action="1_pattern.jsp" method="POST">
            Enter the value of n: <input type="number" name="n" required="required"> <br>
            <input type="hidden" name="submitted" value="true">
            <input type="submit" value="Submit">
        </form>

        <h4>Pattern Using scriptlets:</h4>
        <%
            if(request.getParameter("submitted") != null) {
                // HTML tag input's attribute type="number" will make sure number is entered
                int n = Integer.parseInt(request.getParameter("n"));
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=i;j++) {
                        out.println(j);
                    }
                    out.println("<br>");
                }
            }
        %>

        <h4>Pattern Using &ltc:forEach&gt:</h4>
        <c:forEach var = "i" begin="1" end="${param.n}">
            <c:forEach var="j" begin="1" end="${i}">
                    <c:out value="${j}" />
            </c:forEach>
            <c:out escapeXml="false" value="<br>" />
        </c:forEach>
    </body>
</html>