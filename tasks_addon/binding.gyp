{
    "variables": {},
    "includes": [],
    "targets": [
        {
            "target_name": "tasks_addon",
            "dependencies": ["<!(node -p \"require('node-addon-api').gyp\")" ],
            "include_dirs": [
                "<!@(node -p \"require('node-addon-api').include\")",
                "src/cpp/include"
            ],
            "sources": [
                # adds all .hpp/.cpp files directly under the './src/cpp' directory
                "<!@(node -p \"require('fs').readdirSync('./src/cpp').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/cpp/'+ p).join(' ')\")",
                # adds all .hpp/.cpp files directly under the './src/cpp/include' directory
                "<!@(node -p \"require('fs').readdirSync('./src/cpp/include').filter(p => p.endsWith('.cpp') || p.endsWith('.hpp')).map(p => 'src/cpp/include/'+ p).join(' ')\")"
            ],
            "defines": ['NAPI_CPP_EXCEPTIONS'],
            "conditions": [],
            "msvs_settings": {
                "VCCLCompilerTool": {
                    "RuntimeTypeInfo": "true",
                    "ExceptionHandling": 1 # Suppress C4530 build warnings on Windows
                }
            }
        }
    ],
    "conditions": []
}