<%@ page contentType="text/html" %>
<%@ taglib prefix="t" uri="/WEB-INF/mylib" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<html>
    <body>
        <h4>Usage of custom tag &lt;t:substring input="..." start="1" end="4"&gt; with all mandatory attributes</h4>

        <form method="POST">
            Enter a string: <input type="text" name="str" value="<c:out value="${param.str}"/>"> <br>
            Starting index: <input type="number" name="start" value="<c:out value="${param.start}"/>" > <br>
            Ending index: <input type="number" name="end" value="<c:out value="${param.end}"/>" > <br>
            <input type="hidden" name="submitted" value="true">
            <input type="submit" value="Submit">
        </form>
        <c:if test="${param.submitted}">
            <t:substring input="${param.str}" start="${param.start}" end="${param.end}"/>
        </c:if>
    </body>
</html>