<%@ taglib prefix="spring" uri="http://www.springframework.org/tags"%>
<%@ page contentType="text/html; charset=UTF-8" %>
<html>
<head>
    <title>Spring Eval Example</title>
</head>
<body>
    <h1>Spring Eval Example</h1>
    
    <spring:eval expression="${msg}" var="result" />
    
    <p>Result: ${result}</p>
</body>
</html>