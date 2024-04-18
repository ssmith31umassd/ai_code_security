// JSP
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Expression Evaluation Result</title>
</head>
<body>
    <h1>Expression: ${expression}</h1>
    <c:if test="${not empty error}">
        <p>Error: ${error}</p>
    </c:if>
    <c:if test="${not empty result}">
        <p>Result: ${result}</p>
    </c:if>
</body>
</html>
