<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<h4>Using request.getParameter():</h4> <br>
<%
    int num1 = Integer.parseInt(request.getParameter("num1"));
    int num2 = Integer.parseInt(request.getParameter("num2"));

    int operation = Integer.parseInt(request.getParameter("operation"));
    switch(operation) {
        case 0: out.println("Addition = " + (num1 + num2)); break;
        case 1: out.println("Subtraction = " + (num1 - num2)); break;
        case 2: out.println("Multiplication = " + (num1 * num2)); break;
    }
%>

<h4>Using JSTL Expression Language:</h4> <br>
<c:choose>
    <c:when test="${param.operation == 0}">
        <c:out value="Addition = ${param.num1 + param.num2}" />
    </c:when>
    <c:when test="${param.operation == 1}">
        <c:out value="Subtraction = ${param.num1 - param.num2}" />
    </c:when>
    <c:when test="${param.operation == 2}">
        <c:out value="Multiplication = ${param.num1 * param.num2}" />
    </c:when>        
</c:choose>