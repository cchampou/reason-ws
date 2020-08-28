open Lwt;
open Cohttp;
open Cohttp_lwt_unix;


let fetch = (url) => {
  let body = Client.get(Uri.of_string(url)) >>= fun ((resp, body)) => {
    let code = resp |> Response.status |> Code.code_of_status;
    print_endline(Int.to_string(code));
  
  
    Cohttp_lwt.Body.to_string(body);
  }

  let data = body |> Lwt_main.run;

  data;
}

fetch("http://www.google.fr") |> print_endline;
