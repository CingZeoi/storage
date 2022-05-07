<?php
/*
 author: ZhangCirong
Date: Sat, May 7, 2022
E-Mail: cirong.zhang@outlook.com
URL: https://ip.prc.cx/ipquery.php
*/

ini_set('display_errors', '0');  // 关闭错误提醒

if ($_GET['fn']!="")
{
$fn=$_GET["fn"];
switch ($fn)
{
case "api":
echo(json_encode(QueryIP(($_GET["ip"]==""?GetIP():$_GET["ip"]),$_GET["ipv"])));
break;
case "getip":
echo (GetIP());
break;
default:
echo (GetIP());
break;
}
}
else
{
echo ('
<html>
<head>
<meta charset="utf-8">
<title>'.($_GET['ip']==""?"":"[".$_GET["ip"]."] - ").'赐荣 IP 查询工具</title>
</head>
<body>
<div align="center" id="body">
<a href="https://ip.prc.cx/ipquery.php"><h1>IP 查询</h1></a>
<p>欢迎使用赐荣 IP 查询工具!<br>本工具支持IPv4、IPv6 地址查询,支持域名自动查询 IP 地址。<br>您的 '.(stripos(GetIP(),":")>-1?"IPv6":"IPv4").' 地址是 ['.GetIP().']</p>
<ul id="menu">
<li><a title="可用于测试您的网络是否支持 IPv4" href="https://ipv4.prc.cx/ipquery.php">IPv4 查询</a></li>
<li><a title="可用于测试您的网络是否支持 IPv6" href="https://ipv6.prc.cx/ipquery.php">IPv6 查询</a></li>
</ul>
<form action="ipquery.php" method="get">
<label for="ipbox">输入要查询的IP地址或域名</label>
<input accesskey="/" type="text" id="ipbox" name="ip" title="支持IPv4/IPv6" value="'.$_GET["ip"].'" required></input>
<label for="ipvx">双栈域名优先级</label>
<select accesskey="i" id="ipvx" name="ipv" title="选择优先查询IPv4或IPv6">
<option value="0" title="根据您的网络自动选择">自动</option>
<option value="4" title="优先查询 IPv4 记录">IPv4</option>
<option value="6" title="优先查询 IPv6 记录">IPv6</option>
</select>
<input accesskey="s" type="submit" value="查询"></input>
</form>
'.ShowQueryResult().'
<p>IP 查询接口: https://ip.prc.cx/ipquery.php?fn=api&ip=queryIP</p>
<p>联系信箱:<strong>izcr@qq.com</strong><br>Powered by <a href="https://prc.cx/" target="_blank"><strong>prc.cx</strong></a><br>Copyright © 2020 prc.cx All rights reserved.<br>UA:'.$_SERVER['HTTP_USER_AGENT'].'</p>
</div>
</body>
<script type="text/javascript">
var ipvx = document.getElementById("ipvx");
var ipvxSelectIndex = 0;
var ipv = '.$_GET["ipv"].';
switch(ipv)
{
case 4:
ipvxSelectIndex=1;
break;
case 6:
ipvxSelectIndex=2;
break;
default:
ipvxSelectIndex=0;
break;
}
ipvx.options[ipvxSelectIndex].selected=true;
document.getElementById("ipbox").focus();
</script>
</html>
');
}

function ShowQueryResult()
{
$IPResult=QueryIP(($_GET["ip"]==""?GetIP():$_GET["ip"]),$_GET["ipv"]);
$result="";
if($IPResult->result == null || stripos($IPResult->result->description,"错误的或不完整的IP地址")>-1)
{
$result='<div accesskey="x" id="res" tabindex="0" title="查询结果">
<p>很抱歉!为查询到结果,请检查您输入的查询内容,确保是一个正确的IPv4/IPv6地址或者是一个域名。</p>
</div>';
}
else
{
$result='<div accesskey="x" id="res" tabindex="0" title="查询结果">
<p>您查询的IP是:['.$IPResult->result->queryIP.'];<br>
协议版本:'.$IPResult->result->IPVersion.';<br>
描述:'.$IPResult->result->description.';<br>
位置:'.$IPResult->result->location.';<br>
运营商:'.$IPResult->result->company.'。<br>
声明:查询结果仅供参考,请勿用于重要场合。</p>
</div>';
}
return($result);
}

function QueryIP ($IPAddress,$IPVer = 0)  // 查询 IP地址 (支持IPv4/IPv6)
{
if (preg_Match('#\.[a-zA-Z]{1,62}$#',$IPAddress) > 0)
{
$dnsRes = QueryDomain($IPAddress,$IPVer);
$IPAddress=($dnsRes==""?$IPAddress:$dnsRes);
}
$queryString="https://ip.zxinc.org/api.php?type=json&ip=".$IPAddress;
$gc_ch = curl_init();
curl_setopt($gc_ch, CURLOPT_SSL_VERIFYPEER, FALSE);
curl_setopt($gc_ch, CURLOPT_SSL_VERIFYHOST, FALSE);
curl_setopt($gc_ch, CURLOPT_REFERER,$queryString);
curl_setopt($gc_ch, CURLOPT_URL,$queryString);
curl_setopt($gc_ch, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($gc_ch, CURLOPT_HEADER,0);
$data = curl_exec($gc_ch);
curl_close($gc_ch);
$ipData=json_decode(str_ireplace("cz88.net","prc.cx",$data));
$resultData = new stdClass();
if ($ipData == null)
{
$resultData->code=500;
$resultData->yourIP=GetIp();
$resultData->result=null;
}
else
{
$resultData->code=$ipData->code;
$resultData->yourIP=GetIp();
$queryResult = new stdClass();
$queryResult->queryIP=$IPAddress;
$queryResult->IPVersion=(stripos($IPAddress,":")>-1?"IPv6":"IPv4");
$queryResult->description=$ipData->data->location;
$queryResult->location=($ipData->data->country==""?"未知":$ipData->data->country);
$queryResult->company=($ipData->data->local==""?"prc.cx":$ipData->data->local);
$resultData->result=$queryResult;
}
return($resultData);
}

function GetIP()  // 获取访问者IP地址
{
if (getenv("HTTP_CLIENT_IP") && strcasecmp(getenv("HTTP_CLIENT_IP"), "unknown"))
$ip = getenv("HTTP_CLIENT_IP");
else if (getenv("HTTP_X_FORWARDED_FOR") && strcasecmp(getenv("HTTP_X_FORWARDED_FOR"), "unknown"))
$ip = getenv("HTTP_X_FORWARDED_FOR");
else if (getenv("REMOTE_ADDR") && strcasecmp(getenv("REMOTE_ADDR"), "unknown"))
$ip = getenv("REMOTE_ADDR");
else if (isset($_SERVER['REMOTE_ADDR']) && $_SERVER['REMOTE_ADDR'] && strcasecmp($_SERVER['REMOTE_ADDR'], "unknown"))
$ip = $_SERVER['REMOTE_ADDR'];
else
$ip = "unknown";
return($ip);
}

function QueryDomain ($domain,$type = 0)  // 查询域名 IPv4A记录或IPv6AAAA记录
{
$result="";
switch ($type)
{
case 0 :
if (stripos(GetIP(),":")>-1)
{
$result=dns_get_record($domain,DNS_AAAA)[0]["ipv6"];
if ($result=="")
{
$result=dns_get_record($domain,DNS_A)[0]["ip"];
}
}
else
{
$result=dns_get_record($domain,DNS_A)[0]["ip"];
if($result=="")
{
$result=dns_get_record($domain,DNS_AAAA)[0]["ipv6"];
}
}
break;
case 4 :
$result=dns_get_record($domain,DNS_A)[0]['ip'];
if($result=="")
{
$result=dns_get_record($domain,DNS_AAAA)[0]["ipv6"];
}
break;
case 6 :
$result=dns_get_record($domain,DNS_AAAA)[0]["ipv6"];
if($result=="")
{
$result=dns_get_record($domain,DNS_A)[0]["ip"];
}
break;
default:
$result=dns_get_record($domain,DNS_A)[0]['ip'];
break;
}
return($result);
}
?>
