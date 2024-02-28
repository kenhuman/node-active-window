{
    "targets": [
        {
            "target_name": "node-active-window",
            "cflags!": [ "-fno-exceptions" ],
            "cflags_cc!": [ "-fno-exceptions" ],
            "sources": [ "src/node-active-window.cc" ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")"
            ],
            "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
            "libraries": [
                "User32.lib"
            ],
            "copies": [
                {
                    "destination": "./build/Release",
                    "files": [
                        "./node-active-window.d.ts"
                    ]
                }
            ]
        }
    ]
}