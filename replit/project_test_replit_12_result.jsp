<!-- result.jsp -->
<%@ taglib prefix="spring" uri="http://www.springframework.org/tags" %>
<!DOCTYPE html>
<html>
<head>
    <title>Evaluation Result</title>
</head>
<body>
    <h1>Expression: ${expression}</h1>
    <h2>Result: <spring:eval expression="${expression}" /></h2>
</body>
</html>